#include "XTokenizer.hpp"

XTokenizer::XTokenizer(CharStream & stream) {

    str = stream;

    Tokenize(str);

}

XTokenizer::~XTokenizer() {

    

}

inline auto XTokenizer::Tokenize(CharStream& stream) -> void {

    boost::split(Tokens, stream.ToString(), boost::is_any_of(" \n"));

}

inline auto XTokenizer::Count() -> size_t {

    return str.Size();

}

auto XTokenizer::GetTokens() -> vector<std::string> {

    return Tokens;

}

inline auto XTokenizer::Begin() {

    return Tokens.begin().base();

}

inline auto XTokenizer::End() {

    return Tokens.begin().base();

}

inline auto operator<<(std::ostream& os, const XTokenizer& obj) {

    for(auto &x : obj.Tokens) {

        os << x;

    }

    os << '\n';

}