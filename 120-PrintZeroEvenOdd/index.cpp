#include <iostream>
#include <mutex>
#include <thread>
#include <functional>
#include <condition_variable>

using namespace std;

// Simple function to print a number
void printNumber(int x)
{
    std::cout << x;
}

// Class to coordinate printing 0, odd, and even numbers alternately
class ZeroEvenOdd
{
private:
    int n;                      // Maximum number to print
    int current = 1;            // Current number to print (odd/even)
    std::mutex mtx;             // Mutex for protecting shared data
    std::condition_variable cv; // Condition variable for signaling threads
    int turn = 0;               // Whose turn to print: 0=zero, 1=odd, 2=even

public:
    ZeroEvenOdd(int n)
    {
        this->n = n; // Initialize the maximum number
    }

    // Zero thread: prints 0 n times, alternating with odd/even
    // printNumber(x) is a callback that prints x
    void zero(function<void(int)> printNumber)
    {
        for(int i = 0; i < n; ++i)
        {
            std::unique_lock<std::mutex> lock(mtx); // Lock mutex
            // Wait until it's zero's turn
            cv.wait(lock, [this]{ return turn == 0; });

            printNumber(0); // Print 0

            // Decide which thread prints next: odd or even
            turn = (current % 2 == 1) ? 1 : 2;

            cv.notify_all(); // Wake up waiting threads
        }
    }

    // Even thread: prints even numbers in order
    void even(function<void(int)> printNumber)
    {
        for(; current <= n; )
        {
            std::unique_lock<std::mutex> lock(mtx); // Lock mutex

            // Wait until it's even's turn OR printing is finished
            cv.wait(lock, [this]{ return (turn == 2 || current > n); });

            if(current > n) { break; } // Exit if done

            printNumber(current); // Print current even number
            current++;            // Move to next number
            turn = 0;             // Next turn is zero
            cv.notify_all();      // Wake up zero thread
        }
    }

    // Odd thread: prints odd numbers in order
    void odd(function<void(int)> printNumber)
    {
        for(; current <= n; )
        {
            std::unique_lock<std::mutex> lock(mtx); // Lock mutex

            // Wait until it's odd's turn OR printing is finished
            cv.wait(lock, [this]{ return (turn == 1 || current > n); });

            if(current > n) { break; } // Exit if done

            printNumber(current); // Print current odd number
            current++;            // Move to next number
            turn = 0;             // Next turn is zero
            cv.notify_all();      // Wake up zero thread
        }
    }
};

int main()
{
    ZeroEvenOdd z(5); // Initialize class with n = 5

    // Launch three threads: zero, odd, even
    std::thread t1(&ZeroEvenOdd::zero, &z, printNumber);
    std::thread t2(&ZeroEvenOdd::odd, &z, printNumber);
    std::thread t3(&ZeroEvenOdd::even, &z, printNumber);

    // Wait for all threads to finish
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
