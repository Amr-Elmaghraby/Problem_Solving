#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
    int search(vector<int> &nums,int target){

        int left = 0;
        int right = nums.size()-1;int i=0;
        while(left<=right)
        {
            ++i;
            int mid = left + (right - left)/2; // not to overflow
            if(nums[mid]>target){
                right = mid-1;
            }else if(nums[mid]<target){
                left = mid+1;
            }else{
                std::cout << i<<std::endl;
                return mid;
            }
        }
        std::cout <<i<<std::endl;
        // target not found
        return -1;
    }
};



int main()
{
    // vector<int> nums = {-1,0,3,5,9,12};
    vector<int> nums(100,0);
    for(int i=0;i<nums.size();++i)
    {
        nums[i] = i+1;
    }
    Solution sol;
    std::cout<<sol.search(nums,3)<<std::endl;
    return 0;
}