#include "token.h"

token::token(void)
{
}

static void typeok(int type)
{
        switch (type) {
        case TOK_BOLD:
        case TOK_ERR:
        case TOK_EOF:
        case TOK_LT:
        case TOK_A_TAG:
        case TOK_HREF:
        case TOK_EQ:
        case TOK_STR:
        case TOK_GT:
        case TOK_CHAR:
        case TOK_SLASH:
        case TOK_HTML:
                break;
        default:
                errno = EINVAL;
                err(EX_USAGE, "bad token type: %d", type);
        }
}

token::token(int type)
        : _type {type}
{
        typeok(_type);
}

token::token(int type, int c)
        : _type {type}
{
        typeok(_type);
        _lex += c;
}

token::token(int type, const std::string& lex)
        : _lex {lex},
        _type {type}
{
        typeok(_type);
}

int token::type(void) const
{
        return _type;
}

std::string token::lex(void) const
{
        return _lex;
}

std::string token::name(void) const
{
        std::array<std::string,TOK_COUNT> names {
                "TOK_ERR",
                "TOK_EOF",
                "TOK_LT",
                "TOK_A_TAG",
                "TOK_HREF",
                "TOK_EQ",
                "TOK_STR",
                "TOK_GT",
                "TOK_CHAR",
                "TOK_SLASH",
                "TOK_BOLD",
                "TOK_HTML",
        };
        return names.at(_type);
}
