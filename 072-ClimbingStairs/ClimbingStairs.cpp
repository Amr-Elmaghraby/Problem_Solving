#include <iostream>
#include <vector>
using namespace std;

// Easy solve using Dynamic Programming as it's considered classic DP 
// can be solved using fibonacci sequence 
class Solution
{
    public:
    
    int climbStairs(int n)
    {
        if(n==1){return 1;}

        int prev1 = 1;
        int prev2 = 2;
        for(int i=3;i<=n;++i)
        {
            int current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }

        return prev2;
    }
};


int main()
{
    int n = 7;

    Solution sol;

    std::cout << sol.climbStairs(n);
    return 0;
}