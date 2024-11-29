#include <iostream>
#include <vector>
#include <cmath>

class Solution
{
public:
    int findClosestNumber(std::vector<int> &nums)
    {
        int closest = nums[0];
        for(int num:nums)
        {
            if( ( std::abs(closest) - std::abs(num) ) < 0)
            {
                closest = num;
            }
            else if (std::abs(closest) == std::abs(num) && closest<num)
            {
                closest = num;
            }
        }
        return closest;
    }
};

int main()
{
    std::vector<int> nums = {-4, -2, 1, 4, 8};
    Solution sol;
    int res = sol.findClosestNumber(nums);

    std::cout << res;
    return 0;
}