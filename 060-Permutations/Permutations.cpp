#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:

    void backTrack(vector<int>& nums,int start,vector<vector<int>>& res)
    {
        if(start == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for(int i=start;i<nums.size();++i)
        {
            int tmp = nums[i];
            nums[i] = nums[start];
            nums[start] = tmp;
            backTrack(nums,start+1,res);
            tmp = nums[i];
            nums[i] = nums[start];
            nums[start] = tmp; 
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> perm;
        backTrack(nums,0,perm);
        return perm;
    }
};

std::ostream &operator<<(std::ostream &os, vector<vector<int>> &vec)
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
    os << "]";
    return os;
}

int main()
{
    Solution sol;
    vector<int> vec = {1, 2, 3};
    vector<vector<int>> res = sol.permute(vec);

    std::cout << res;
    return 0;
}