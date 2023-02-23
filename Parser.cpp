#include "Parser.hpp"

Parser::Parser() {

    tokens.reserve(256);

}

Parser::Parser(vector<string> tokens){

    this->tokens = tokens;

}

auto Parser::GenerateTree() -> void {


    
}