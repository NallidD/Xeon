#include "XTokenizer.hpp"

auto main(int argc, char * argv[]) -> int {

    CharStream stream("Hello World!");
    
    XTokenizer tkn(stream);

    vector<std::string> toks = tkn.GetTokens();

    for(auto &x : toks) {

        std::cout << x << '\n';

    }

    std::cout << stream << '\n';

    //end

    return 0;

}