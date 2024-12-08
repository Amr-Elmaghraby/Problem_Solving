#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
    public:
    int findKthLargest(vector<int>&nums,int k)
    {
        if(nums.size()==0 || k > nums.size()){return 0;}
        std::map<int,int> mp;
        for(int i=0;i<k;++i)
        {
            ++mp[nums[i]];
        }
        for(int i=k;i<nums.size();++i)
        {
            auto start = mp.begin();
            if(nums[i]>=start->first)
            {
                ++mp[nums[i]];
                --(start->second);
                if(start->second == 0)
                {
                    mp.erase(start);
                }
            }
        }

        return mp.begin()->first;
    }

};


int main()
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    Solution sol;
    std::cout << sol.findKthLargest(nums,4);
    return 0;
}