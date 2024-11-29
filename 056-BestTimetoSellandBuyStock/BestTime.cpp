#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX; // Initialize to maximum possible value
        int maxProfit = 0;

        for (int price : prices)
        {
            // Update the minimum price if the current price is lower
            minPrice = std::min(minPrice, price);

            // Calculate the profit if selling at current price
            int profit = price - minPrice;

            // Update the maximum profit
            maxProfit = std::max(maxProfit, profit);
        }

        return maxProfit;
    }
};

int main()
{
    vector<int> vec = {5,100,2,3,0,0,0,0,1,1000};
    // vector<int> vec = {5, 5, 4, 9, 3, 8, 5, 5, 1, 6, 8, 3, 4};
    // vector<int> vec = {1, 2};

    Solution sol;
    int res = sol.maxProfit(vec);

    std::cout << res << std::endl;
    return 0;
}