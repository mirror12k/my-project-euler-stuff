
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

// find the largest prime factor of a number
// not sure how well this will work on a 32bit system
void problem_3()
{
    cout << "problem #3" << endl;

    long long number = 600851475143;

    vector<long long> prime_factors = prime_factorize(number);
    // last prime factor in the list (returned in sorted order)
    int largest_factor = prime_factors[prime_factors.size() - 1];

    cout << "prime factors of " << number << ": " << to_string_vector(prime_factors) << endl;
    cout << "largest prime factor of " << number << ": " << largest_factor << endl;
}

// find the largest palindrome product of two 3-digit numbers
void problem_4()
{
    cout << "problem #4" << endl;

    // calculate all products of 3-digit numbers
    vector<int> all_numbers = range(100, 1000);
    vector<int> all_products = cross_product(all_numbers, all_numbers);

    // calculate which are palindromes, select, then sort them
    vector<bool> which_palindromes = map_vector(all_products, is_palindrome_number);
    vector<int> all_palindromes = select_vector(all_products, which_palindromes);
    std::sort(all_palindromes.begin(), all_palindromes.end());

    // select the largest one at the end
    int largest_palindrome = all_palindromes[all_palindromes.size() - 1];

    cout << "largest palindrome product of two 3-digit numbers: " << largest_palindrome << endl;
}

// find the smallest number evenly divisible by all numbers 1 to 20
void problem_5()
{
    cout << "problem #5" << endl;

    int limit = 20;

    int n = 1;
    for (int i = 1; i <= limit; i++)
    {
        // skip i if n is already evenly divisible by it
        if (n % i != 0)
        {
            int broken_n = n;
            vector<int> factors = prime_factorize(i);
            // iterate through the prime factors of i to find the one missing from n
            while (broken_n % factors.back() == 0)
            {
                broken_n /= factors.back();
                factors.pop_back();
            }
            // multiply n by the missing factor
            n *= factors.back();
        }
    }

    cout << "smallest number evenly divisible by all numbers 1 to " << limit << ": " << n << endl;
}

// find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum
void problem_6()
{
    cout << "problem #6" << endl;

    int limit = 100;

    vector<int> numbers = range(1, limit + 1);
    // calculate the sum of the squares
    vector<int> squares = map_vector(numbers, square<int>);
    int sum_of_squares = sum(squares);
    // calculate the square of the sum
    int square_of_sum = square(sum(numbers));

    // calculate difference
    int difference = square_of_sum - sum_of_squares;

    cout << "difference between the sum of the squares and the square of the sum of 1 to " << limit << ": " << difference << endl;
}

// find the 10001st prime
void problem_7()
{
    cout << "problem #7" << endl;

    int index = 10001;

    vector<int> primes = prime_sequence(index);
    int prime = primes[index - 1];

    cout << "prime #" << index << ": " << prime << endl;
}












