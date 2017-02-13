
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

// find a factor for the given number, or 1 if not found
long long find_factor(long long n)
{
    for (long long i = 2; i < sqrt(n); i++)
        if (n % i == 0)
            return i;
    return 1;
}

// factorize a number into its primes
vector<long long> prime_factorize(long long n)
{
    vector<long long> result;

    long long factor = find_factor(n);
    while (factor != 1)
    {
        result.push_back(factor);
        n /= factor;
        factor = find_factor(n);
    }
    result.push_back(n);

    return result;
}







