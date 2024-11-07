#include "lexer.h"

static std::unordered_map<std::string,int> kwords {
        {"download", TOK_DOWNLOAD},
        {"hreflang", TOK_HREFLANG},
        {"media", TOK_MEDIA},
        {"ping", TOK_PING},
        {"referrerpolicy", TOK_REFERRER_POLICY},
        {"rel", TOK_REL},
        {"target", TOK_TARGET},
        {"type", TOK_TYPE},
        {"xmlns", TOK_XMLNS},
        {"accesskey", TOK_ACCESS_KEY},
        {"lang", TOK_LANG},
        {"autocapitalize", TOK_AUTO_CAPITALIZE},
        {"href", TOK_HREF},
	{"abbr", TOK_ABBR_TAG},
	{"a", TOK_A_TAG},
	{"body", TOK_BODY_TAG},
	{"bold", TOK_BOLD_TAG},
	{"div", TOK_DIV_TAG},
	{"html", TOK_HTML_TAG},
	{"p", TOK_P_TAG},
	{"table", TOK_TABLE_TAG},
	{"area", TOK_AREA_TAG},
	{"article", TOK_ARTICLE_TAG},
	{"aside", TOK_ASIDE_TAG},
	{"audio", TOK_AUDIO_TAG},
	{"b", TOK_B_TAG},
	{"base", TOK_BASE_TAG},
	{"bdi", TOK_BDI_TAG},
	{"bdo", TOK_BDO_TAG},
	{"blockquote", TOK_BLOCKQUOTE_TAG},
	{"br", TOK_BR_TAG},
	{"button", TOK_BUTTON_TAG},
	{"canvas", TOK_CANVAS_TAG},
	{"caption", TOK_CAPTION_TAG},
	{"cite", TOK_CITE_TAG},
	{"code", TOK_CODE_TAG},
	{"col", TOK_COL_TAG},
	{"colgroup", TOK_COLGROUP_TAG},
	{"data", TOK_DATA_TAG},
	{"datalist", TOK_DATALIST_TAG},
	{"dd", TOK_DD_TAG},
	{"del", TOK_DEL_TAG},
	{"details", TOK_DETAILS_TAG},
	{"dfn", TOK_DFN_TAG},
	{"dialog", TOK_DIALOG_TAG},
	{"dl", TOK_DL_TAG},
	{"dt", TOK_DT_TAG},
	{"em", TOK_EM_TAG},
	{"embed", TOK_EMBED_TAG},
	{"fieldset", TOK_FIELDSET_TAG},
	{"figcaption", TOK_FIGCAPTION_TAG},
	{"figure", TOK_FIGURE_TAG},
	{"footer", TOK_FOOTER_TAG},
	{"form", TOK_FORM_TAG},
	{"h1", TOK_H1_TAG},
	{"head", TOK_HEAD_TAG},
	{"header", TOK_HEADER_TAG},
	{"hgroup", TOK_HGROUP_TAG},
	{"hr", TOK_HR_TAG},
	{"i", TOK_I_TAG},
	{"iframe", TOK_IFRAME_TAG},
	{"img", TOK_IMG_TAG},
	{"input", TOK_INPUT_TAG},
	{"ins", TOK_INS_TAG},
	{"kbd", TOK_KBD_TAG},
	{"label", TOK_LABEL_TAG},
	{"legend", TOK_LEGEND_TAG},
	{"li", TOK_LI_TAG},
	{"link", TOK_LINK_TAG},
	{"main", TOK_MAIN_TAG},
	{"map", TOK_MAP_TAG},
	{"mark", TOK_MARK_TAG},
	{"menu", TOK_MENU_TAG},
	{"meta", TOK_META_TAG},
	{"meter", TOK_METER_TAG},
	{"nav", TOK_NAV_TAG},
	{"noscript", TOK_NOSCRIPT_TAG},
	{"object", TOK_OBJECT_TAG},
	{"ol", TOK_OL_TAG},
	{"optgroup", TOK_OPTGROUP_TAG},
	{"option", TOK_OPTION_TAG},
	{"output", TOK_OUTPUT_TAG},
	{"picture", TOK_PICTURE_TAG},
	{"pre", TOK_PRE_TAG},
	{"progress", TOK_PROGRESS_TAG},
	{"q", TOK_Q_TAG},
	{"rp", TOK_RP_TAG},
	{"rt", TOK_RT_TAG},
	{"ruby", TOK_RUBY_TAG},
	{"s", TOK_S_TAG},
	{"samp", TOK_SAMP_TAG},
	{"script", TOK_SCRIPT_TAG},
	{"search", TOK_SEARCH_TAG},
	{"section", TOK_SECTION_TAG},
	{"select", TOK_SELECT_TAG},
	{"slot", TOK_SLOT_TAG},
	{"small", TOK_SMALL_TAG},
	{"source", TOK_SOURCE_TAG},
	{"span", TOK_SPAN_TAG},
	{"strong", TOK_STRONG_TAG},
	{"style", TOK_STYLE_TAG},
	{"sub", TOK_SUB_TAG},
	{"summary", TOK_SUMMARY_TAG},
	{"sup", TOK_SUP_TAG},
	{"tbody", TOK_TBODY_TAG},
	{"td", TOK_TD_TAG},
	{"template", TOK_TEMPLATE_TAG},
	{"textarea", TOK_TEXTAREA_TAG},
	{"tfoot", TOK_TFOOT_TAG},
	{"th", TOK_TH_TAG},
	{"thead", TOK_THEAD_TAG},
	{"time", TOK_TIME_TAG},
	{"title", TOK_TITLE_TAG},
	{"tr", TOK_TR_TAG},
	{"track", TOK_TRACK_TAG},
	{"u", TOK_U_TAG},
	{"ul", TOK_UL_TAG},
	{"var", TOK_VAR_TAG},
	{"video", TOK_VIDEO_TAG},
	{"wbr", TOK_WBR_TAG},
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

static void skip_comment(FILE *fp);

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
                        if ((c = fgetc(_fp)) == '!') {
                                skip_comment(_fp);
                                continue;
                        }
                        _putback = c;
                        return token{TOK_LT};
                case '>':
                        return token{TOK_GT};
                case '=':
                        return token{TOK_EQ};
                case '"':
                        s = "";
                        while ((c = fgetc(_fp)) != EOF && c != '"')
                                s += c;
                        if (c == EOF) {
                                errno = EINVAL;
                                err(EX_USAGE, "bad string");
                        }
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

static void skip_comment(FILE *fp)
{
        for (;;) {
                errno = EINVAL;

                auto c = fgetc(fp);
                if (c == EOF)
                        err(EX_USAGE, "invalid comment");
                if (c != '-')
                        continue;

                c = fgetc(fp);
                if (c == EOF)
                        err(EX_USAGE, "invalid comment");
                if (c != '-')
                        continue;

                c = fgetc(fp);
                if (c == EOF)
                        err(EX_USAGE, "invalid comment");
                if (c != '>')
                        continue;

                errno = 0;
                break;
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
