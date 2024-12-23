#include <iostream>
#include <vector>
using namespace std;


class Solution
{
    public:
    int findMin(vector<int> & nums)
    {
        if(nums.size()==0){return 0;}
        int left = 0;
        int right = nums.size()-1;
        
        while(left<right)
        {
            int mid = left +(right-left)/2;
            if(nums[mid]>nums[right]){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return nums[left];
    }
};


int main()
{
    vector<int> nums = {3,1,2};
    Solution sol;
    std::cout << sol.findMin(nums);
    return 0;
}