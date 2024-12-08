#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
    public:
    int findKthLargest(vector<int> &nums,int k)
    {
        std::priority_queue<int,std::vector<int>,std::greater<int>> minHeap;

        for(int num:nums)
        {
            minHeap.push(num);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};


int main()
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    Solution sol;
    std::cout << sol.findKthLargest(nums,4);
    return 0;
}