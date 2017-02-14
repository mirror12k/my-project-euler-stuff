
#pragma once

#include <vector>
#include <array>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iterator>

using std::vector;
using std::array;
using std::string;



// is a number odd
bool is_odd(int n);
// is a number even
bool is_even(int n);
// is a string a palindrome
bool is_palindrome(string s);
// is a number palindrome
bool is_palindrome_number(int n);


// utility functions for use in callbacks
// convert a character digit into its numeric equivalent
template <typename T>
T from_digit(char c);

// square a number
template <typename T>
T square(T n);

// sum of arithmetic series of factor 1
template <typename T>
T sum_of_arithemtic_sequence(T n);


// produce a vector of ints from start to end - 1
template <typename T>
vector<T> range(T start, T end);
// produce a sum of all values in vec
template <typename T>
T sum(const vector<T>& vec);
// produce a product of all values in vec
template <typename T>
T product(const vector<T>& vec);
// produce all possible combinations of products of two vectors
vector<int> cross_product(const vector<int>& vec1, const vector<int>& vec2);
// find the maximum value in a vector
template <typename T>
T max(const vector<T>& vec);
// find the minimum value in a vector
template <typename T>
T min(const vector<T>& vec);


// produce a sequence of fibonacci numbers less than limit
vector<int> fibonacci_sequence(int limit);
// produce a sequence of triangle numbers less than limit
template <typename T>
vector<T> triangle_numbers_sequence(T limit);

// find a factor for the given number, or 0 if not found
template <typename T>
T find_factor(T n);
// find all possible factors of a given number, including 1 and itself
template <typename T>
vector<T> factorize(T n);

// factorize a number into its primes
template <typename T>
vector<T> prime_factorize(T n);

// compute a sequence of the first n primes
template <typename T>
vector<T> prime_sequence(T n);

// compute a sequence of primes less than limit
template <typename T>
vector<T> prime_sequence_until(T limit);

// compute a sequence of primes less than limit using a giant memory array (faster for limited sequence sizes)
template <typename T>
vector<T> arrayd_prime_sequence_until(T limit);

// compute all subsequences of length characters in the string
vector<string> subsequences(const string& str, int length);



// map a vector from using a basic mapping function
template <typename T, typename R>
vector<R> map_vector(const vector<T>& vec, R (*map_function)(T));
// select values from vec into a resulting vector based on the bools in the selection vec
template <typename T>
vector<T> select_vector(const vector<T>& vec, const vector<bool>& selection);

// convert a vector of items to a pretty string
template <typename T>
string to_string_vector(const vector<T>& vec);



/************************************************************/
// definitions of template functions:



// convert a character digit into its numeric equivalent
template <typename T>
T from_digit(char c)
{
    return c - '0';
}


template <typename T>
T square(T n)
{
    return n * n;
}

// sum of arithmetic series of factor 1
template <typename T>
T sum_of_arithemtic_sequence(T n)
{
    return n * (n + 1) / 2;
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
T sum(const vector<T>& vec)
{
    T sum = 0;
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        sum += *iter;
    return sum;
}

// produce a product of all values in vec
template <typename T>
T product(const vector<T>& vec)
{
    T product = 1;
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        product *= *iter;
    return product;
}

// find the maximum value in a vector
template <typename T>
T max(const vector<T>& vec)
{
    T max = vec.front();
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        if (*iter > max)
            max = *iter;
    return max;
}

// find the minimum value in a vector
template <typename T>
T min(const vector<T>& vec)
{
    T min = vec.front();
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        if (*iter < min)
            min = *iter;
    return min;
}





// produce a sequence of triangle numbers less than limit
template <typename T>
vector<T> triangle_numbers_sequence(T limit)
{
    vector<T> seq;

    T i = 1;
    T triangle = sum_of_arithemtic_sequence(i);
    while (triangle < limit)
    {
        seq.push_back(triangle);
        i++;
        triangle = sum_of_arithemtic_sequence(i);
    }

    return seq;
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

// find all possible factors of a given number, including 1 and itself
template <typename T>
vector<T> factorize(T n)
{
    vector<T> factors;

    T sqrt_of_n = std::sqrt(n);
    for (T i = 1; i < sqrt_of_n; i++)
        if (n % i == 0)
        {
            factors.push_back(i);
            factors.push_back(n / i);
        }
    if (sqrt_of_n * sqrt_of_n == n)
        factors.push_back(sqrt_of_n);
    return factors;
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

template <typename T>
bool is_divisible_by(T n, const vector<T>& vec)
{
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        if (n % *iter == 0)
            return true;
    return false;
}

// compute a sequence of the first n primes
template <typename T>
vector<T> prime_sequence(T n)
{
    vector<T> seq;

    seq.push_back(2);
    for (T v = 3; seq.size() < n; v += 2)
        if (!is_divisible_by(v, seq))
            seq.push_back(v);

    return seq;
}

// compute a sequence of primes less than limit
template <typename T>
vector<T> prime_sequence_until(T limit)
{
    vector<T> seq;

    if (limit > 2)
        seq.push_back(2);
    for (T v = 3; v < limit; v += 2)
        if (!is_divisible_by(v, seq))
            seq.push_back(v);

    return seq;
}

// compute a sequence of primes less than limit using a giant memory array
template <typename T>
vector<T> arrayd_prime_sequence_until(T limit)
{
    // allocate a number table to mark out a map of all primes
    vector<bool> number_table;
    for (T i = 0; i < limit; i++)
        number_table.push_back(true);

    // for each number
    for (T i = 2; i < limit; i++)
        // if it is prime
        if (number_table[i] == true)
            // iterate over all multiples of it, marking them non-prime
            for (T j = i * i; j < limit; j += i)
                number_table[j] = false;

    // collect the remaining primes in a final array
    vector<T> primes;
    for (T i = 2; i < limit; i++)
        if (number_table[i] == true)
            primes.push_back(i);

    return primes;
}





// map a vector from using a basic mapping function
template <typename T, typename R>
vector<R> map_vector(const vector<T>& vec, R (*map_function)(T))
{
    vector<R> result;

    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        result.push_back(map_function(*iter));
    return result;
}

// select values from vec into a resulting vector based on the bools in the selection vec
template <typename T>
vector<T> select_vector(const vector<T>& vec, const vector<bool>& selection)
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
string to_string_vector(const vector<T>& vec)
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
