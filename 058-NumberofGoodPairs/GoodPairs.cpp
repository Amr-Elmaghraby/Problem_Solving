#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
    public:
    int numIdenticalPairs(vector<int>& nums){
        int goodPairs=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i)
        {
            ++mp[nums[i]];
        }
        for(std::unordered_map<int,int>::iterator it = mp.begin();it !=mp.end();++it)
        {
           goodPairs += (it->second*(it->second-1))/2;
        }
        return goodPairs;
    }
};



int main(){
    vector<int> nums = {5,5,1,77,96,96,89,80,12,23,1,6,3,66,39,88,48,38,44,32,44,36,60,87,53,77,72,49,13,39,60,60,71,68,80,75,79,38,4,14,59,75,6,91,87,95,25,55,83,18,26,59,53,100,42,96,76,22,21,4,22,46,34,39,98,82,54,73,52,33,47,73,54,23,82,98,13,51,52,1,96,69,76};
    Solution sol;
    int res = sol.numIdenticalPairs(nums);

    std::cout << res;


    return 0;
}