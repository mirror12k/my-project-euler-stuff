
#include "math_util.hpp"



// produce a sum of all integers in vec
int sum(vector<int> vec)
{
    int sum = 0;
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        sum += *iter;
    return sum;
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
