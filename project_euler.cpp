
#include "project_euler.hpp"
#include "math_util.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;



// find the sum of all positive integer multiples of 3 or 5 that are less than 1000
void problem_1()
{
    cout << "problem #1" << endl;

    int limit = 1000;
    vector<int> multiples_of_3_or_5;

    for (int i = 0; i < limit; i++)
        if (i % 3 == 0 || i % 5 == 0)
            multiples_of_3_or_5.push_back(i);

    int sum_multiples = sum(multiples_of_3_or_5);

    cout << "sum of multiples of 3 or 5 (below " << limit << "): " << sum_multiples << endl;
}


// find the sum of all even valued fibonacci numbers less than 4 million
void problem_2()
{
    cout << "problem #2" << endl;

    int limit = 4000000; //4_000_000
    vector<int> fibonacci_numbers = fibonacci_sequence(limit);
    vector<bool> even_selections = map_vector(fibonacci_numbers, is_even);
    vector<int> even_fibonacci_numbers = select_vector(fibonacci_numbers, even_selections);

    int sum_fibonacci_evens = sum(even_fibonacci_numbers);

    cout << "sum of even fibonacci numbers (below " << limit << "): " << sum_fibonacci_evens << endl;
}
