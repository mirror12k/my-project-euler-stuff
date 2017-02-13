
#pragma once

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iterator>

using std::vector;
using std::string;



// is a number odd
bool is_odd(int n);
// is a number even
bool is_even(int n);
// is a string a palindrome
bool is_palindrome(string s);
// is a number palindrome
bool is_palindrome_number(int n);


// square a number
template <typename T>
T square(T n);

// produce a vector of ints from start to end - 1
template <typename T>
vector<T> range(T start, T end);
// produce a sum of all integers in vec
template <typename T>
T sum(vector<T> vec);
// produce all possible combinations of products of two vectors
vector<int> cross_product(vector<int>& vec1, vector<int>& vec2);

// produce a sequence of fibonacci numbers less than limit
vector<int> fibonacci_sequence(int limit);

// find a factor for the given number, or 0 if not found
template <typename T>
T find_factor(T n);

// factorize a number into its primes
template <typename T>
vector<T> prime_factorize(T n);



// map a vector from using a basic mapping function
template <typename T, typename R>
vector<R> map_vector(vector<T>& vec, R (*map_function)(T));
// select values from vec into a resulting vector based on the bools in the selection vec
template <typename T>
vector<T> select_vector(vector<T>& vec, vector<bool>& selection);

// convert a vector of items to a pretty string
template <typename T>
string to_string_vector(vector<T>& vec);



/************************************************************/
// definitions of template functions:


template <typename T>
T square(T n)
{
    return n * n;
}



// produce a vector of ints from start to end - 1
template <typename T>
vector<T> range(T start, T end)
{
    vector<T> result;
    for (T i = start; i < end; i++)
        result.push_back(i);
    return result;
}

// produce a sum of all integers in vec
template <typename T>
T sum(vector<T> vec)
{
    T sum = 0;
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        sum += *iter;
    return sum;
}




// find a factor for the given number, or 1 if not found
template <typename T>
T find_factor(T n)
{
    for (T i = 2; i <= std::sqrt(n); i++)
        if (n % i == 0)
            return i;
    return 1;
}

// factorize a number into its primes
template <typename T>
vector<T> prime_factorize(T n)
{
    vector<T> result;

    T factor = find_factor(n);
    while (factor != 1)
    {
        result.push_back(factor);
        n /= factor;
        factor = find_factor(n);
    }
    result.push_back(n);

    return result;
}





// map a vector from using a basic mapping function
template <typename T, typename R>
vector<R> map_vector(vector<T>& vec, R (*map_function)(T))
{
    vector<R> result;

    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        result.push_back(map_function(*iter));
    return result;
}

// select values from vec into a resulting vector based on the bools in the selection vec
template <typename T>
vector<T> select_vector(vector<T>& vec, vector<bool>& selection)
{
    vector<T> result;

    auto select_iter = selection.begin();
    for (auto iter = vec.begin(); iter != vec.end() && select_iter != selection.end(); iter++, select_iter++)
        if (*select_iter)
            result.push_back(*iter);
    return result;
}


// convert a vector of items to a pretty string
// mostly taken from https://stackoverflow.com/questions/8581832/converting-a-vector-to-string
template <typename T>
string to_string_vector(vector<T>& vec)
{
    std::ostringstream oss;

    if (!vec.empty())
    {
        // Convert all but the last element to avoid a trailing ","
        std::copy(vec.begin(), vec.end()-1, std::ostream_iterator<T>(oss, ","));
        // Now add the last element with no delimiter
        oss << vec.back();
    }

    return "{" + oss.str() + "}";
}
