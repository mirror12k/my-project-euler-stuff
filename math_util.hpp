
#pragma once

#include <vector>

using std::vector;



// produce a sum of all integers in vec
int sum(vector<int> vec);

// produce a sequence of fibonacci numbers less than limit
vector<int> fibonacci_sequence(int limit);

// is a number odd
bool is_odd(int n);
// is a number even
bool is_even(int n);


// map a vector from using a basic mapping function
template <typename T, typename R>
vector<R> map_vector(vector<T>& vec, R (*map_function)(T));
// select values from vec into a resulting vector based on the bools in the selection vec
template <typename T>
vector<T> select_vector(vector<T>& vec, vector<bool>& selection);



template <typename T, typename R>
vector<R> map_vector(vector<T>& vec, R (*map_function)(T))
{
    vector<R> result;

    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        result.push_back(map_function(*iter));
    return result;
}

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
