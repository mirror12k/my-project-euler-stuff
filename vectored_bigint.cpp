
#include "vectored_bigint.hpp"

vectored_bigint::vectored_bigint()
: vector<char>()
{}

// reads a string of digits and loads the bigint from them
vectored_bigint::vectored_bigint(const string& s)
: vector<char>()
{
    for (auto iter = s.rbegin(); iter != s.rend(); iter++)
        this->push_back(*iter - '0');
}


// adds an integer value to the bigint
vectored_bigint vectored_bigint::operator+(int value) const
{
    vectored_bigint result;

    int carry = value;
    // if there are any remaining digits in either number, add them over with carry
    for (auto iter = this->begin(); iter != this->end(); iter++)
    {
        carry += *iter;
        result.push_back(carry % 10);
        carry /= 10;
    }
    // if we still have a carry, push it into the result
    while (carry != 0)
    {
        result.push_back(carry % 10);
        carry /= 10;
    }

    return result;
}

// adds together the two bigints into a new third bigint
vectored_bigint vectored_bigint::operator+(const vectored_bigint& other) const
{
    vectored_bigint result;

    // sum together all digits
    auto iter_this = this->cbegin(), iter_other = other.begin();
    int carry = 0;
    while (iter_this != this->cend() && iter_other != other.end())
    {
        result.push_back((*iter_this + *iter_other + carry) % 10);
        // compute next carry
        carry = (*iter_this + *iter_other + carry) / 10;
        iter_this++;
        iter_other++;
    }

    // if there are any remaining digits in either number, add them over with carry
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
    // if we still have a carry, push it into the result
    if (carry != 0)
        result.push_back(carry);

    return result;
}

// multiplies the bigint by some integer value
vectored_bigint vectored_bigint::operator*(int value) const
{
    vectored_bigint result;

    int carry = 0;
    // if there are any remaining digits in either number, add them over with carry
    for (auto iter = this->begin(); iter != this->end(); iter++)
    {
        carry += value * *iter;
        result.push_back(carry % 10);
        carry /= 10;
    }
    // if we still have a carry, push it into the result
    while (carry != 0)
    {
        result.push_back(carry % 10);
        carry /= 10;
    }

    return result;
}

//// multiplies together the two bigints into a new third bigint
//vectored_bigint vectored_bigint::operator*(const vectored_bigint& other) const
//{
//    vectored_bigint result;
//
//    // for each digit in other
//        // multiply each digit in us by the other
//        // add to result
//
//}

// converts the bigint back to a string
string vectored_bigint::to_string() const
{
    string result = "";
    for (auto iter = this->rbegin(); iter != this->rend(); iter++)
        result += *iter + '0';
    return result;
}


