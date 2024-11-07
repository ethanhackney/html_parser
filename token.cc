#include "token.h"

token::token(void)
{
}

static void typeok(int type)
{
        switch (type) {
        case TOK_ERR:
        case TOK_EOF:
        case TOK_LT:
        case TOK_HREF:
        case TOK_EQ:
        case TOK_STR:
        case TOK_GT:
        case TOK_CHAR:
        case TOK_SLASH:
        case TOK_DOWNLOAD:
        case TOK_HREFLANG:
        case TOK_MEDIA:
        case TOK_PING:
        case TOK_REFERRER_POLICY:
        case TOK_REL:
        case TOK_TARGET:
        case TOK_TYPE:
        case TOK_XMLNS:
        case TOK_ACCESS_KEY:
        case TOK_LANG:
        case TOK_AUTO_CAPITALIZE:
	case TOK_ABBR_TAG:
	case TOK_A_TAG:
	case TOK_BODY_TAG:
	case TOK_BOLD_TAG:
	case TOK_DIV_TAG:
	case TOK_HTML_TAG:
	case TOK_P_TAG:
	case TOK_TABLE_TAG:
	case TOK_AREA_TAG:
	case TOK_ARTICLE_TAG:
	case TOK_ASIDE_TAG:
	case TOK_AUDIO_TAG:
	case TOK_B_TAG:
	case TOK_BASE_TAG:
	case TOK_BDI_TAG:
	case TOK_BDO_TAG:
	case TOK_BLOCKQUOTE_TAG:
	case TOK_BR_TAG:
	case TOK_BUTTON_TAG:
	case TOK_CANVAS_TAG:
	case TOK_CAPTION_TAG:
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
                "TOK_HREF",
                "TOK_EQ",
                "TOK_STR",
                "TOK_GT",
                "TOK_CHAR",
                "TOK_SLASH",
                "TOK_DOWNLOAD",
                "TOK_HREFLANG",
                "TOK_MEDIA",
                "TOK_PING",
                "TOK_REFERRER_POLICY",
                "TOK_REL",
                "TOK_TARGET",
                "TOK_TYPE",
                "TOK_XMLNS",
                "TOK_ACCESS_KEY",
                "TOK_LANG",
                "TOK_AUTO_CAPITALIZE",
		"TOK_ABBR_TAG",
		"TOK_A_TAG",
		"TOK_BODY_TAG",
		"TOK_BOLD_TAG",
		"TOK_DIV_TAG",
		"TOK_HTML_TAG",
		"TOK_P_TAG",
		"TOK_TABLE_TAG",
		"TOK_AREA_TAG",
		"TOK_ARTICLE_TAG",
		"TOK_ASIDE_TAG",
		"TOK_AUDIO_TAG",
		"TOK_B_TAG",
		"TOK_BASE_TAG",
		"TOK_BDI_TAG",
		"TOK_BDO_TAG",
		"TOK_BLOCKQUOTE_TAG",
		"TOK_BR_TAG",
		"TOK_BUTTON_TAG",
		"TOK_CANVAS_TAG",
		"TOK_CAPTION_TAG",
        };
        return names.at(_type);
}
