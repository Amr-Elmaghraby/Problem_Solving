#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> sums;
        if(nums.size()<3){return sums;}
        std::sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();++i)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }

            int left = i+1;
            int right = nums.size()-1;

            // Use two pointers to find pairs that sum to -nums[i]
            while(left<right)
            {
                int sum = nums[i]+nums[left]+nums[right];
                // If the sum of the triplet is zero
                if(sum==0)
                {
                    // Add the triplet to the result
                    sums.push_back({nums[i],nums[left],nums[right]});
                    // Skip duplicates for the second number
                    while(left<right && nums[left]==nums[left+1])
                    {
                        ++left;
                    }
                    // Skip duplicates for the third number
                    while(left<right && nums[right]==nums[right-1])
                    {
                        --right;
                    }

                    // Move both pointers after recording the triplet
                    ++left;
                    --right;
                }
                else if (sum<0){
                    ++left;
                }
                else{
                    --right;
                }
            }
        }
        return sums;
    }
};

std::ostream &operator<<(std::ostream &os, vector<vector<int>> vec)
{
    os << "[";
    for (int i = 0; i < vec.size(); ++i)
    {
        os << "[";
        for (int j = 0; j < vec[i].size(); ++j)
        {
            os << vec[i][j];
            if (j != vec[i].size() - 1)
            {
                os << ",";
            }
        }
        os << "]";
        if (i != vec.size() - 1)
        {
            os << ",";
        }
    }
    os << "]" << std::endl;
    return os;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<int> nums = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    Solution sol;
    vector<vector<int>> res = sol.threeSum(nums);
    std::cout << res;
    return 0;
}