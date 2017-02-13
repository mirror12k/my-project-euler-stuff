
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


string problem_8_data = "73167176531330624919225119674426574742355349194934"
            "96983520312774506326239578318016984801869478851843"
            "85861560789112949495459501737958331952853208805511"
            "12540698747158523863050715693290963295227443043557"
            "66896648950445244523161731856403098711121722383113"
            "62229893423380308135336276614282806444486645238749"
            "30358907296290491560440772390713810515859307960866"
            "70172427121883998797908792274921901699720888093776"
            "65727333001053367881220235421809751254540594752243"
            "52584907711670556013604839586446706324415722155397"
            "53697817977846174064955149290862569321978468622482"
            "83972241375657056057490261407972968652414535100474"
            "82166370484403199890008895243450658541227588666881"
            "16427171479924442928230863465674813919123162824586"
            "17866458359124566529476545682848912883142607690042"
            "24219022671055626321111109370544217506941658960408"
            "07198403850962455444362981230987879927244284909188"
            "84580156166097919133875499200524063689912560717606"
            "05886116467109405077541002256983155200055935729725"
            "71636269561882670428252483600823257530420752963450";

// find thirteen adjacent digits that have the largest product
void problem_8()
{
    cout << "problem #8" << endl;

    int adjacent = 13;

    vector<string> digits = subsequences(problem_8_data, adjacent);
    vector<long long> products;
    for (auto iter = digits.begin(); iter != digits.end(); iter++)
    {
        vector<char> char_digits(iter->begin(), iter->end());
        vector<long long> numeric_digits = map_vector(char_digits, from_digit<long long>);
        products.push_back(product(numeric_digits));
    }

    // sort the products to find the greatest
    std::sort(products.begin(), products.end());

    long long largest_product = products[products.size() - 1];

    cout << "largest product in sequences of length " << adjacent << ": " << largest_product << endl;
//    cout << "sequences of length " << adjacent << ": " << to_string_vector(products) << endl;
}

// find the product abc for a,b,c such that a + b + c = 1000 and a,b,c is a pythagorean triplet
void problem_9()
{
    cout << "problem #9" << endl;

    int found_a = 0, found_b = 0, found_c = 0;

    for (int c = 1; c < 1000; c++)
    {
        for (int b = 1; b < c; b++)
        {
            for (int a = 1; a < b; a++)
            {
                if (a + b + c == 1000)
                {
                    if (a * a + b * b == c * c)
                    {
                        found_a = a;
                        found_b = b;
                        found_c = c;
                    }
                }
            }
        }
    }

    cout << "a,b,c such that a + b + c = 1000 and a,b,c is a pythagorean triplet : " << found_a << ", " << found_b << ", " << found_c << endl;
    cout << "product of a*b*c: " << found_a * found_b * found_c << endl;
}


// find the sum of primes below 2 million
void problem_10()
{
    cout << "problem #10" << endl;

    long long limit = 2000000;

//    vector<long long> primes = prime_sequence_until<long long>(limit);
    vector<long long> primes = arrayd_prime_sequence_until<long long>(limit);
    long long sum_of_primes = sum(primes);

    cout << "count primes below " << limit << ": " << primes.size() << endl;
    cout << "sum of primes below " << limit << ": " << sum_of_primes << endl;
}
















