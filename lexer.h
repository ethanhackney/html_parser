#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <string>
#include <cerrno>
#include <err.h>
#include <sysexits.h>
#include <cstdio>
#include <cctype>
#include <unordered_map>

class lexer {
private:
        std::string _path {};
        token _cur {};
        token _peek {};
        FILE* _fp {nullptr};
        bool _intag {false};
        int _putback {0};
        token next_tok(void);
public:
        lexer(const std::string& path);
        ~lexer();
        token next(void);
        token cur(void) const;
        token peek(void) const;
        int type(void) const;
        std::string lex(void) const;
        std::string name(void) const;
        void skip(int type);
};

#endif
