
#include "math_util.hpp"



// is a number odd
bool is_odd(int n)
{
    return n % 2 == 1;
}
// is a number even
bool is_even(int n)
{
    return n % 2 == 0;
}

// is a string a palindrome
bool is_palindrome(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - i - 1])
            return false;
    return true;
}

// is a number palindrome
bool is_palindrome_number(int n)
{
    string str = std::to_string(n);
    return is_palindrome(str);
}



// produce all possible combinations of products of two vectors
vector<int> cross_product(vector<int>& vec1, vector<int>& vec2)
{
    vector<int> result;

    for(auto iter1 = vec1.begin(); iter1 != vec1.end(); iter1++)
        for(auto iter2 = vec2.begin(); iter2 != vec2.end(); iter2++)
            result.push_back(*iter1 * *iter2);
    return result;
}

// produce a sequence of fibonacci numbers less than limit
vector<int> fibonacci_sequence(int limit)
{
    vector<int> seq;

    seq.push_back(1);
    seq.push_back(2);
    while (seq[seq.size() - 2] + seq[seq.size() - 1] < limit)
        seq.push_back(seq[seq.size() - 2] + seq[seq.size() - 1]);
    return seq;
}


// compute all subsequences of length characters in the string
vector<string> subsequences(const string& str, int length)
{
    vector<string> result;
    for (int i = 0; i <= str.size() - length; i++)
        result.push_back(str.substr(i, length));
    return result;
}










