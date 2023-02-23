all:
	g++ -std=gnu++20 -std=c++20 -O3 parser.cpp -o parser

parser:
	g++ -std=gnu++20 -std=c++20 -O3 parser.cpp -o parser

asmsrc:
	g++ -std=gnu++20 -std=c++20 -Ofast -S -o source.s parser.cpp

stream:
	g++ -std=gnu++20 -std=c++20 -ggdb CharStream.hpp XTokenizer.cpp main.cpp

clean:
	rm parser sourse.s

