#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return cost[0];
        if (n == 2)
            return min(cost[0], cost[1]);

        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i)
        {
            dp[i] = cost[i] + min( (i-1)>=0?dp[i-1]:0 , (i-2)>=0?dp[i-2]:0);
        }

        return min(dp[n - 1], dp[n - 2]);
    }
};

int main()
{
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    // vector<int> cost = {10, 15, 20};
    Solution sol;
    std::cout << sol.minCostClimbingStairs(cost);
    return 0;
}