#include <string_view>
#include <vector>
#include <string>

#include "XeonSet.hpp"
#include "XTokenizer.hpp"

using std::string_view;
using std::vector;
using std::string;

class Parser {

private:

    struct Node {

        Node * left;
        string_view data;
        Node * right;

    };

    struct AST {

        Node * root;
        char * op;
        char * sym;
        string_view word;

    };

    AST * tree;
    vector<string> tokens;

    auto GenerateTree() -> void;

public:

    Parser();
    Parser(vector<string> tokens);

};