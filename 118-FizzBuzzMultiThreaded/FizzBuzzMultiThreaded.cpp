#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std;

// Class to run FizzBuzz using 4 separate threads
class FizzBuzz {
private:
    int n;                   // Maximum number to count up to
    mutex mx;                 // Mutex to synchronize access to shared 'itr'
    condition_variable cv;    // Condition variable to coordinate thread execution
    int itr = 1;              // Current number being processed

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // Called by the "fizz" thread: prints "fizz" for numbers divisible by 3 but not 5
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(mx);  // Lock mutex for safe access to 'itr'
            // Wait until: either finished (itr > n) OR itr divisible by 3 but not by 5
            cv.wait(lock, [this] { return (itr > n) || ((itr % 3 == 0) && (itr % 5 != 0)); });
            if (itr > n) { return; }      // Exit loop if all numbers processed
            printFizz();                  // Print "fizz"
            itr++;                        // Move to next number
            cv.notify_all();              // Wake up all threads to check their conditions
        }
    }

    // Called by the "buzz" thread: prints "buzz" for numbers divisible by 5 but not 3
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(mx);
            // Wait until: finished OR itr divisible by 5 but not by 3
            cv.wait(lock, [this] { return (itr > n) || ((itr % 3 != 0) && (itr % 5 == 0)); });
            if (itr > n) { return; }
            printBuzz();    // Print "buzz"
            itr++;
            cv.notify_all();
        }
    }

    // Called by the "fizzbuzz" thread: prints "fizzbuzz" for numbers divisible by both 3 and 5
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(mx);
            // Wait until: finished OR itr divisible by both 3 and 5
            cv.wait(lock, [this] { return (itr > n) || ((itr % 3 == 0) && (itr % 5 == 0)); });
            if (itr > n) { return; }
            printFizzBuzz(); // Print "fizzbuzz"
            itr++;
            cv.notify_all();
        }
    }

    // Called by the "number" thread: prints the number if not divisible by 3 or 5
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mx);
            // Wait until: finished OR itr not divisible by 3 or 5
            cv.wait(lock, [this]() { return (itr > n) || ((itr % 3 != 0) && (itr % 5 != 0)); });
            if (itr > n) { return; }
            printNumber(itr++); // Print the current number and increment
            cv.notify_all();
        }
    }
};

// Output functions used by the threads
void printFizz() { cout << "fizz"; }
void printBuzz() { cout << "buzz"; }
void printFizzBuzz() { cout << "fizzbuzz"; }
void printNumber(int n) { cout << n; }

int main() {
    FizzBuzz fb(15); // Create a FizzBuzz instance for numbers 1..15

    // Start 4 threads, each responsible for one type of output
    std::thread A(&FizzBuzz::fizz, &fb, printFizz);
    std::thread B(&FizzBuzz::buzz, &fb, printBuzz);
    std::thread C(&FizzBuzz::fizzbuzz, &fb, printFizzBuzz);
    std::thread D(&FizzBuzz::number, &fb, printNumber);

    // Wait for all threads to finish
    A.join();
    B.join();
    C.join();
    D.join();

    return 0;
}
