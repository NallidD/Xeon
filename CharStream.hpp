#ifndef XEON_CHAR_STREAM_H
#define XEON_CHAR_STREAM_H

#include <vector>
#include <string>
#include <string_view>
#include <iostream>
#include <cstring>

using std::vector;
using std::size_t;
using std::string;
using std::string_view;

constexpr size_t STREAM_MAX = 25600;

class CharStream {

private:

    /// @brief The CharStream's buffer, represented by vector<char>
    vector<char> stream;

    /// @brief If CharStream's buffer size exceeds STREAM_MAX (25600), flush the buffer. Saves space complexity.
    /// @return void
    inline auto FlushStream() -> void { /* If we reach max buffer size, flush the stream. */

        stream.assign(stream.size(), 0);

    }

    /// @brief Determines if CharStream's buffer overflows the limit STREAM_MAX (25600).
    /// @return True if overflow occurs, false otherwise.
    inline auto State() -> bool {

        if(stream.size() >= STREAM_MAX) {

            FlushStream();

            return true;

        }

        return false;

    }

public:

    /// @brief Reserves space of size STREAM_MAX (25600), CharStream must call Assign to insert values into the Stream
    CharStream() { stream.reserve(STREAM_MAX); }

    /// @brief Initializes the CharStream with another vector<char>, copying the contents of the vector into the CharStream
    /// @param stream 
    CharStream(vector<char> &stream) { stream.reserve(STREAM_MAX); this->stream = stream; }

    /// @brief Takes a char * stream to initialize the stream. The user must pass in the size, which is used to reserve space.
    /// @param stream 
    /// @param size 
    CharStream(char * stream, size_t size) {

        this->stream.reserve(size);
        this->stream.insert(this->stream.begin(), stream, stream + size);

    }

    /// @brief Takes a const char * to initialize the stream. Space is reserved by the array's size (via strlen) and inserted.
    /// @param stream 
    CharStream(const char * stream) {

        size_t size = strlen(stream);

        this->stream.reserve(size);
        this->stream.insert(this->stream.begin(), stream, stream + size);

    }

    /// @brief Takes a std::string passed by copy to initialize the stream. Space is reserved with the string's size and inserted.
    /// @param stream 
    CharStream(std::string stream) {

        this->stream.reserve(stream.size());
        this->stream.insert(this->stream.begin(), stream.begin(), stream.end());

    }

    /// @brief Takes a std::string by reference to initialize the stream. Space is reserved by string's size and contents are inserted.
    /// @param stream 
    CharStream(std::string &stream) {

        this->stream.reserve(stream.size());
        this->stream.insert(this->stream.begin(), stream.begin(), stream.end());

    }

    /// @brief Takes a std::string_view passed by copy to initialize the stream. Space is reserved with the string_view's size and inserted into the CharStream
    /// @param stream 
    CharStream(std::string_view stream) {

        this->stream.reserve(stream.size());
        this->stream.insert(this->stream.begin(), stream.begin(), stream.end());

    }

    /// @brief Takes a std::string_view by reference to initialize the stream. Space is reserved by string_view's size and contents are inserted.
    /// @param stream 
    CharStream(std::string_view &stream) {

        this->stream.reserve(stream.size());
        this->stream.insert(this->stream.begin(), stream.begin(), stream.end());

    }

    /// @brief 
    /// Template constructor of CharStream for compile time known size of size N for parameter stream
    /// @tparam N 
    /// @param stream 
    template<size_t N>
    CharStream(char (&stream)[N]) {

        this->stream.reserve(N);
        this->stream.insert(this->stream.begin(), stream, stream + N);

    }

    /// @brief 
    /// @return The number of elements contained with our stream
    inline auto Size() -> size_t {

        return stream.size();

    }

    /// @brief 
    /// @tparam N 
    /// @param stream 
    /// Clears the stream and fills the CharStream with parameter char(&stream)[N]
    /// This templated function allows for the template parameter size_t N, the size of the array stream, to be known at compile time.
    /// @return void
    template<size_t N>
    inline auto Assign(char (&stream)[N]) -> void {

        this->stream.clear();

        this->stream.insert(this->stream.begin(), stream, stream + N);

    }

    /// @brief 
    /// @param stream
    /// Clears the stream and fills it with parameter const char * stream. 
    /// @return void
    inline auto Assign(const char * stream) -> void {

        size_t size = strlen(stream);
        this->stream.clear();

        this->stream.insert(this->stream.begin(), stream, stream + size);

    }

    /// @brief 
    /// @param stream 
    /// Clears the stream and fills it with parameter string stream. Removes null terminator of the string.
    /// @return void
    inline auto Assign(string &stream) -> void {

        this->stream.clear();

        for(auto &x : stream) {

            this->stream.emplace_back(x);

        }

        if(*(this->stream.end().base()) == '\n') { /* Don't care about whitespaces and new lines. */

            this->stream.erase(this->stream.end());

        }

    }

    /// @brief 
    /// @param stream 
    /// Clears the stream, then fills our CharStream with parameter string_view stream
    /// @return void
    inline auto Assign(string_view &stream) -> void {

        this->stream.clear();

        for(auto &x : stream) {

            this->stream.emplace_back(x);

        }

    }

    /// @brief 
    /// @param index 
    /// Retuns the value at position index
    /// @return Reference to type char at index
    inline auto & At(size_t index) {

        return stream.at(index);

    }

    /// @brief 
    /// Returns the value of the beginning position, that is, returns the first value of the CharStream
    /// @return Reference to type char at index 0
    inline auto & Begin() {

        return stream.at(0);

    }

    /// @brief 
    /// Returns the value of the end position, that is, returns the last value of the CharStream.
    /// @return  Reference to type char at index size - 1
    inline auto & End() {

        return stream.at(stream.size() - 1);

    }

    /// @brief 
    /// Returns the underlying value of CharStream, which is a vector<char>
    /// @return Reference to type vector<char>
    inline auto Base() -> vector<char> & {

        return stream;

    }


    /// @brief 
    /// Returns a copy of a string that is taken from the stream which is a vector<char>
    /// @return Copy of a std::string representing the data of the stream
    inline auto ToString() -> std::string { // Copy

        return std::string(stream.begin(), stream.end());

    }

    /// @brief 
    /// Returns a copy of a string_view that is taken from the stream which is a vector<char>
    /// @return Copy of a std::string_view representing the data of the stream
    inline auto ToStringView() -> std::string_view { // Copy

        return std::string_view(stream.begin(), stream.end());

    }

    /// @brief 
    /// @param os 
    /// @param stream 
    /// Puts contents of CharStream into an std::ostream &os buffer for printing the contents with std::cout
    /// @return The contents of the stream pushed into std::ostream &os
    friend inline auto operator<<(std::ostream &os, CharStream &stream) -> std::ostream & {

        for(unsigned int i = 0; i < stream.Size(); i++) {

            os << stream.At(i);

        }

        return os;

    }

};

#endif