#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

// This class ensures the methods are called in the order:
// first() -> second() -> third()
class Foo {
private:
    mutex mtx;                      // Mutex to protect shared access to 'stage'
    condition_variable cv;          // Condition variable for thread synchronization
    int stage = 0;                  // Shared state variable indicating progress:
                                    // 0 = nothing done, 1 = first done, 2 = second done

public:
    Foo() {}

    // first() must run before second() and third()
    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);   // Lock the mutex for exclusive access
        printFirst();                   // Execute the provided function (e.g., print "first")
        stage = 1;                      // Mark that first() has completed
        cv.notify_all();                // Notify all waiting threads (second() and third())
    }

    // second() must wait until first() has completed
    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);   // Lock the mutex
        // Wait until stage >= 1 (i.e., first() is done)
        cv.wait(lock, [this]() { return stage >= 1; });
        printSecond();                  // Execute the function (e.g., print "second")
        stage = 2;                      // Mark that second() has completed
        cv.notify_all();                // Notify remaining waiting threads (e.g., third())
    }

    // third() must wait until second() has completed
    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);   // Lock the mutex
        // Wait until stage >= 2 (i.e., second() is done)
        cv.wait(lock, [this]() { return stage >= 2; });
        printThird();                   // Execute the function (e.g., print "third")
        // No need to update stage or notify anymore since this is the last function
    }
};

// Raw print functions (can also use lambdas or functors)
void printFirstFunc()  { cout << "first"; }
void printSecondFunc() { cout << "second"; }
void printThirdFunc()  { cout << "third"; }

int main() {
    Foo foo;

    // Threads will run the functions in arbitrary order,
    // but synchronization ensures correct output order.

    // Pass raw function pointers wrapped in std::function
    thread t1(&Foo::first,  &foo, printFirstFunc);
    thread t2(&Foo::second, &foo, printSecondFunc);
    thread t3(&Foo::third,  &foo, printThirdFunc);

    // Wait for all threads to finish
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
