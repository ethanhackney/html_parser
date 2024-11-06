CFLAGS = -std=c++11 -Wall -Werror -pedantic -fsanitize=address,undefined
SRC    = abbr_node.cc a_node.cc body_node.cc bold_node.cc div_node.cc html_node.cc p_node.cc table_node.cc text_node.cc node.cc main.cc dump_visitor.cc parser.cc lexer.cc token.cc
CC     = g++
all: $(SRC)
	$(CC) $(CFLAGS) $^
