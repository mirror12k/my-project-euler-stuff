
#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;



// custom definition for a vectored bigint which uses characters to represent each digit of a number
class vectored_bigint : public vector<char>
{
public:
    vectored_bigint();
    vectored_bigint(const string& s);

    vectored_bigint operator+(const vectored_bigint& other);

    string to_string();
};
