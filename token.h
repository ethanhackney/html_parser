#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <array>
#include <cerrno>
#include <err.h>
#include <sysexits.h>

enum {
        TOK_ERR,
        TOK_EOF,
        TOK_LT,
        TOK_EQ,
        TOK_STR,
        TOK_GT,
        TOK_HREF,
        TOK_CHAR,
        TOK_SLASH,
        TOK_DOWNLOAD,
        TOK_HREFLANG,
        TOK_MEDIA,
        TOK_PING,
        TOK_REFERRER_POLICY,
        TOK_REL,
        TOK_TARGET,
        TOK_TYPE,
        TOK_XMLNS,
        TOK_ACCESS_KEY,
        TOK_LANG,
        TOK_AUTO_CAPITALIZE,
	TOK_ABBR_TAG,
	TOK_A_TAG,
	TOK_BODY_TAG,
	TOK_BOLD_TAG,
	TOK_DIV_TAG,
	TOK_HTML_TAG,
	TOK_P_TAG,
	TOK_TABLE_TAG,
	TOK_AREA_TAG,
	TOK_ARTICLE_TAG,
	TOK_ASIDE_TAG,
	TOK_AUDIO_TAG,
	TOK_B_TAG,
	TOK_BASE_TAG,
	TOK_BDI_TAG,
	TOK_BDO_TAG,
	TOK_BLOCKQUOTE_TAG,
	TOK_BR_TAG,
	TOK_BUTTON_TAG,
	TOK_CANVAS_TAG,
	TOK_CAPTION_TAG,
        TOK_COUNT,
};

class token {
private:
        std::string _lex {""};
        int _type {TOK_ERR};
public:
        token(void);
        token(int type);
        token(int type, int c);
        token(int type, const std::string& lex);
        int type(void) const;
        std::string lex(void) const;
        std::string name(void) const;
};

#endif
