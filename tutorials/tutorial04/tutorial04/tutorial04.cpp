#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <chrono>

void greet(std::string name = "Guest") {
    std::cout << "Hello, " << name << "!\n";
}

void introduce(std::string name = "Guest", int age = 18) {
    std::cout << name << " is " << age << " years old.\n";
}

void show(int a, int b = 5, int c = 10) {
    std::cout << a << " " << b << " " << c << "\n";
}

void test(int x = 1, double y = 2.5) {
    std::cout << "First function\n";
}

void test(double x=4.5) {
    std::cout << "Second function\n";
}

struct Point
{
    int x;
    int y;

    friend std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

template<typename T>
void display(T value) {
    std::cout << "Value: " << value << "\n";
}

template <typename T, typename U>
void showPair(T a, U b) {
    std::cout << a << " and " << b << "\n";
}

template <typename T, typename U>
auto max(T a, U b) -> decltype(a > b ? a : b)//decltype is stange syntax and I wouldn't normally suggest it but this is fun to play with anyways.
//decltype() determines return type, not value, and ? is comparing the type of a to the type of b therefor giving the "greater" type. 
{
    if (a > b) return a;
    else return b;
}

int main() {
    /*greet();//prints Guest because it is defined as default argument in function above
    greet("Alice");

    introduce();//default both name and age as defined
    introduce("Bob");//default age as defined
    introduce("Charlie", 25); //prints "Charlie is 25 years old." because both defined here

    show(1, 2);*/

    //test();

    /*display(42);
    display(3.14);
    display("Hello");
    display(Point{ 3,4 });*/

    /*showPair(10, 3.5);
    showPair("Alice", 42);*/

    
    auto result = max(3, 4.5);
    //returns double bc double is more presice; no loss occurs when changing int to double

    auto result1 = max(7, 1.0f);
    //returns float bc a float, similar to double, can represent more integers; converting float to int could cause truncation

    auto result2 = max(1L, static_cast<short>(2));
    //returns long bc 1L is a long and longs can store all short values; converting long to short could cause overflow
     
    auto result3 = max(2L, static_cast<short>(1));
    //returns long for same reason as above

    auto result4 = max(444.4f, 222.2);
    //returns double bc double has higher precision than float (64 bit vs 32 bit); converting double to float would loose precision


    const int N = 100'000;

    std::vector<int> v;
    std::list<int> l;
    std::deque<int> d;

    /*push_back Timing:
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) v.push_back(i);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Vector: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) l.push_back(i);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "List: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) d.push_back(i);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Deque: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";*/
    
    /*push_front Timing :
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) v.insert(v.begin(), i); //vector doesn't have push_front but this is functionally the same
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Vector: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
 
 
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) l.push_front(i);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "List: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
 
 
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) d.push_front(i);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Deque: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";*/


    /*Use vector for most things. (85%)  If you need to add or remove from both ends, use a deque. (10%) In a very 
    weird situation where you need to add and remove from the middle a lot, use list. (<5%)*/
    return 0;
}
