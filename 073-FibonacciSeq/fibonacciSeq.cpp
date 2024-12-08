#include <iostream>

// the Fibonacci numbers, commonly denoted F(n) form a sequence,
// called the Fibonacci sequence, such that each number is the
// sum of the two preceding ones, starting from 0 and 1. That is,
// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }

        --n;
        int n_2 = 1;
        int n_1 = 2;
        for (int i = 3; i <= n; ++i)
        {
            int current = n_2 + n_1;
            n_2 = n_1;
            n_1 = current;
        }
        return n_1;
    }
};

int main()
{
    int n = 3;
    Solution sol;
    std::cout << sol.fib(n);
    return 0;
}