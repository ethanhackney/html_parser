#include "lexer.h"

static std::unordered_map<std::string,int> kwords {
        {"a", TOK_A_TAG},
        {"href", TOK_HREF},
        {"bold", TOK_BOLD},
        {"html", TOK_HTML},
        {"download", TOK_DOWNLOAD},
        {"hreflang", TOK_HREFLANG},
        {"media", TOK_MEDIA},
        {"ping", TOK_PING},
        {"referrerpolicy", TOK_REFERRER_POLICY},
        {"rel", TOK_REL},
        {"target", TOK_TARGET},
        {"type", TOK_TYPE},
        {"body", TOK_BODY},
        {"xmlns", TOK_XMLNS},
};

lexer::lexer(const std::string& path)
        : _path {path},
        _fp {fopen(path.c_str(), "r")}
{
        if (_fp == nullptr)
                err(EX_SOFTWARE, "could not open %s", _path.c_str());
}

lexer::~lexer()
{
        if (fclose(_fp) < 0)
                err(EX_SOFTWARE, "could not close %s", _path.c_str());
}

token lexer::next(void)
{
        if (_peek.type() != TOK_ERR)
                _cur = _peek;
        else
                _cur = next_tok();

        if (_cur.type() == TOK_EOF)
                return _cur;

        if (_cur.type() == TOK_LT)
                _intag = true;
        if (_cur.type() == TOK_GT)
                _intag = false;

        _peek = next_tok();
        return _cur;
}

token lexer::next_tok(void)
{
        for (;;) {
                auto c = _putback;
                if (c != 0)
                        _putback = 0;
                else
                        c = fgetc(_fp);

                if (_intag && isspace(c))
                        continue;

                std::string s;
                switch (c) {
                case EOF:
                        return token{TOK_EOF};
                case '<':
                        return token{TOK_LT};
                case '>':
                        return token{TOK_GT};
                case '=':
                        return token{TOK_EQ};
                case '"':
                        s = "";
                        while ((c = fgetc(_fp)) != '"')
                                s += c;
                        return token{TOK_STR, s};
                case '/':
                        return token{TOK_SLASH};
                }

                if (_intag && isalpha(c)) {
                        s = "";
                        while (isalpha(c)) {
                                s += c;
                                c = fgetc(_fp);
                        }
                        _putback = c;

                        auto p = kwords.find(s);
                        if (p != kwords.end())
                                return token{p->second, s};

                        errno = EINVAL;
                        err(EX_USAGE, "bad word: %s", s.c_str());
                }

                return token{TOK_CHAR, c};
        }
}

token lexer::cur(void) const
{
        return _cur;
}

token lexer::peek(void) const
{
        return _peek;
}

int lexer::type(void) const
{
        return _cur.type();
}

std::string lexer::lex(void) const
{
        return _cur.lex();
}

std::string lexer::name(void) const
{
        return _cur.name();
}

void lexer::skip(int type)
{
        if (_cur.type() == type) {
                next();
                return;
        }
        errno = EINVAL;
        err(EX_USAGE, "expected %s, got %s",
                token{type}.name().c_str(), _cur.name().c_str());
}
