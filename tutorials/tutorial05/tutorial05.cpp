#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>
 
int main() {
    /*Iterators - The Basics: Understanding begin() and end()
      Iterators allow traversing containers like std::vector, std::set, and std::map. The functions begin() 
      and end() provide iterator access to the start and end of a container.*/
    //std::vector<int> numbers = {1, 2, 3, 4, 5};
    //std::vector<int>::iterator it = numbers.begin();
    //std::cout << "First element: " << *it << std::endl;

    /*Moving Iterators: next() and prev().
      the std::next(it, n) and std::prev()it, n functions allow moving an iterator forward or backward.*/
    //std::vector<int> numbers = {10, 20, 30, 40, 50};
    //auto it = numbers.begin();
    //auto nextIt = std::next(it, 2);
    //std::cout << "Value at nextIt: " << *nextIt << std::endl;
    
    //Using iterators in loops
    //std::vector<int> nums = {1, 2, 3, 4, 5};
    //for (auto it = nums.begin(); it != nums.end(); ++it) {
        //std::cout << *it << " ";
    //}

    /*Standard Algorithms with Iterators
      std::accumulate
      std::accumulate is used to sum elements in a range.*/
    //std::vector<int> values = {1, 2, 3, 4, 5};
    //int sum = std::accumulate(values.begin(), values.end(), 0);
    //std::cout << "Sum: " << sum << std::endl;

    /*std::for_each*/
    //std::for_each(nums.begin(), nums.end(), [](int n) { std::cout << n << " "; });

    /*Lambda Functions and Sorting: Sorting with Lambdas*/
    std::vector<int> values = {5, 2, 8, 3, 1};
    std::sort(values.begin(), values.end(), [](int a, int b) { return a%2 < b%2; });
    for (int v : values) {
        std::cout << v << " ";
    }
    return 0;
    
}