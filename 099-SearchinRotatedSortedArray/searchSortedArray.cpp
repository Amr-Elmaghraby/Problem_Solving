#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
    int search(vector<int> &nums,int target)
    {
        if(nums.size() == 0){return 0;}
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;

            if(nums[mid] == target){
                return mid;
            }

            // Determine which part is sorted

            // left part is sorted
            if(nums[left]<=nums[mid])
            {
                // Target is in the left sorted part 
                if(nums[left]<=target && target < nums[mid]){
                    right = mid - 1;
                }else{
                    left = mid+1;
                }
            }else{ // Right part is sorted
                if(nums[mid] <target&& target <= nums[right]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums={4,5,6,7,0,1,2};
    int target = 0;
    Solution sol;
    std::cout << sol.search(nums,target);
    return 0;
}