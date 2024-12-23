#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = 0;
        std::stack<int> stk;
        heights.push_back(0);// to pop all remaining bars at the end 
        for(int i=0;i<heights.size();++i)
        {
            while(!stk.empty()&&heights[i]<heights[stk.top()])
            {
                int h = heights[stk.top()];
                stk.pop();
                int w = (stk.empty())?i:(i-stk.top()-1);
                maxArea = std::max(maxArea,h*w);
            }
            stk.push(i);
        }
        return maxArea;
    }
};

int main()
{
    vector<int> heights = {2, 0, 5, 6, 2, 3,1,1,1,1,1,1,1};
    // vector<int> heights = {1,1,1,1,1,1,1,1,1,100,1,1,1,1,1};
    Solution sol;
    std::cout << sol.largestRectangleArea(heights);
}