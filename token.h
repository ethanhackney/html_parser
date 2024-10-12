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
        TOK_A_TAG,
        TOK_HREF,
        TOK_EQ,
        TOK_STR,
        TOK_GT,
        TOK_CHAR,
        TOK_SLASH,
        TOK_BOLD,
        TOK_HTML,
        TOK_DOWNLOAD,
        TOK_HREFLANG,
        TOK_MEDIA,
        TOK_PING,
        TOK_REFERRER_POLICY,
        TOK_REL,
        TOK_TARGET,
        TOK_TYPE,
        TOK_BODY,
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
