#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
    int searchInsert(vector<int> &nums,int target)
    {
        if(!nums.size()){return 0;}
        int left = 0;
        int right = nums.size()-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] == target)
            {
                return mid;
            }else if(nums[mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return left;
    }
};

int main()
{
    vector<int> nums ={-1,0,1,3,4,5,6,7,8,9,10,11,13,14,15,17,20,209,254,725,999,1000};
    Solution sol;
    std::cout << sol.searchInsert(nums,12);
    return 0;
}