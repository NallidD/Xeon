#ifndef XEON_XTOKENIZER_H
#define XEON_XTOKENIZER_H

class XTokenizer;

#include "CharStream.hpp"

#include <boost/algorithm/string.hpp>

class XTokenizer {

private:

    vector<std::string> Tokens;
    CharStream str;
    inline auto Tokenize(CharStream& stream) -> void;

public:

    XTokenizer() = delete;
    XTokenizer(CharStream & stream);
    ~XTokenizer();

    inline auto Count() -> size_t;
    auto GetTokens() -> vector<std::string>;
    inline auto Begin();
    inline auto End();
    friend inline auto operator<<(std::ostream& os, const XTokenizer& obj);

};

#endif