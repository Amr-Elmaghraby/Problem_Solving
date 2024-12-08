#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            if (map.count(num))
            {
                if ((i - map[num]) <= k)
                {
                    return true;
                }
            }
            map[num] = i;
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {1, 0, 1, 1};
    int k = 1;
    Solution sol;
    bool res = sol.containsNearbyDuplicate(nums, k);

    std::cout << res;

    return 0;
}