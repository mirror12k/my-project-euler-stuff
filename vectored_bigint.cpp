
#include "vectored_bigint.hpp"

vectored_bigint::vectored_bigint()
: vector<char>()
{}

vectored_bigint::vectored_bigint(const string& s)
: vector<char>()
{
    for (auto iter = s.rbegin(); iter != s.rend(); iter++)
        this->push_back(*iter - '0');
}


vectored_bigint vectored_bigint::operator+(const vectored_bigint& other)
{
    vectored_bigint result;

    auto iter_this = this->cbegin(), iter_other = other.begin();
    int carry = 0;
    while (iter_this != this->cend() && iter_other != other.end())
    {
        result.push_back((*iter_this + *iter_other + carry) % 10);
        carry = (*iter_this + *iter_other + carry) / 10;
        iter_this++;
        iter_other++;
    }

    while (iter_this != this->cend())
    {
        result.push_back((*iter_this + carry) % 10);
        carry = (*iter_this + carry) / 10;
        iter_this++;
    }
    while (iter_other != other.end())
    {
        result.push_back((*iter_other + carry) % 10);
        carry = (*iter_other + carry) / 10;
        iter_other++;
    }
    if (carry != 0)
        result.push_back(carry);

    return result;
}

string vectored_bigint::to_string()
{
    string result = "";
    for (auto iter = this->rbegin(); iter != this->rend(); iter++)
        result += *iter + '0';
    return result;
}


