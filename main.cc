#include "dump_visitor.h"
#include "lexer.h"
#include "parser.h"
#include <iostream>

int main(void)
{
        lexer l {"index.html"};
        parser p {l};

        p.parse();

        node_visitor* dv = new dump_visitor{};
        for (size_t r = 0; r < p.n_roots(); r++) {
                p.get_root(r)->visit(dv);
                std::cout << "\n";
        }

        delete dv;
}
