
#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;



// custom definition for a vectored bigint which uses characters to represent each digit of a number
// implemented as a char vector which stores least significant digit first and most significant digit last
class vectored_bigint : public vector<char>
{
public:
    vectored_bigint();
    // reads a string of digits and loads the bigint from them
    vectored_bigint(const string& s);

    // adds an integer value to the bigint
    vectored_bigint operator+(int value) const;
    // adds together the two bigints into a new third bigint
    vectored_bigint operator+(const vectored_bigint& other) const;
    // multiplies the bigint by some integer value
    vectored_bigint operator*(int value) const;
    // multiplies together the two bigints into a new third bigint
    vectored_bigint operator*(const vectored_bigint& other) const;

    // converts the bigint back to a string
    string to_string() const;
};
