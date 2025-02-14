
/**
 * @file MaxMoneyRob.cpp
 * @brief Solution to the House Robber problem.
 * 
 * This file contains the implementation of a solution to the House Robber problem,
 * where the goal is to determine the maximum amount of money that can be robbed
 * from a series of houses without robbing two adjacent houses.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @class Solution
 * @brief Provides a method to solve the House Robber problem.
 */
class Solution
{
public:
    /**
     * @brief Computes the maximum amount of money that can be robbed without robbing two adjacent houses.
     * 
     * @param nums A vector of integers representing the amount of money in each house.
     * @return The maximum amount of money that can be robbed.
     */
    int rob(vector<int> &nums)
    {
        int dp_prev2 = 0, dp_prev1 = 0;

        // Iterate through each house's money
        for (int curr : nums)
        {
            int tmp = dp_prev1;
            // Update prev1 to be the maximum of robbing the current house or not
            dp_prev1 = std::max(dp_prev1, curr + dp_prev2);
            // Update prev2 to the previous value of prev1
            dp_prev2 = tmp;
        }

        // Return the maximum amount of money that can be robbed
        return dp_prev1;
    }
};

int main()
{
    // Example vector of house money values
    vector<int> nums = {1, 2, 134, 4, 2, 21, 4, 42, 123, 14, 10};
    // Another example vector of house money values
    // vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10};

    Solution sol;

    // Output the result of the rob function
    std::cout << sol.rob(nums);
    return 0;
}