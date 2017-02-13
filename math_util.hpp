
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

// produce a vector of ints from start to end - 1
vector<int> range(int start, int end);
// produce a sum of all integers in vec
int sum(vector<int> vec);
// produce all possible combinations of products of two vectors
vector<int> cross_product(vector<int>& vec1, vector<int>& vec2);

// produce a sequence of fibonacci numbers less than limit
vector<int> fibonacci_sequence(int limit);

// find a factor for the given number, or 0 if not found
long long find_factor(long long n);

// factorize a number into its primes
vector<long long> prime_factorize(long long n);



// map a vector from using a basic mapping function
template <typename T, typename R>
vector<R> map_vector(vector<T>& vec, R (*map_function)(T));
// select values from vec into a resulting vector based on the bools in the selection vec
template <typename T>
vector<T> select_vector(vector<T>& vec, vector<bool>& selection);

// convert a vector of items to a pretty string
template <typename T>
string to_string_vector(vector<T>& vec);




// definitions of template functions:

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
