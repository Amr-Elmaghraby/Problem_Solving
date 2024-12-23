#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int Area = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left <= right)
        {
            int currentArea = std::min(height[left],height[right])*(right-left);
            Area = std::max(currentArea,Area);
            if(height[left]<height[right])
            {
                ++left;
            }else{
                --right;
            }
        }
        return Area;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    std::cout << sol.maxArea(height);
    return 0;
}