CFLAGS  = -std=c++11 -Wall -Werror -pedantic -fsanitize=address,undefined
SRC     = main.cc token.cc lexer.cc node.cc text_node.cc a_node.cc \
	  	bold_node.cc dump_visitor.cc parser.cc html_node.cc \
		p_node.cc body_node.cc div_node.cc
CC      = g++

all: $(SRC)
	$(CC) $(CFLAGS) $^
