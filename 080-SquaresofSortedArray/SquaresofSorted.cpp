#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Squaring each element and sorting the new array is very trivial,
//  could you find an O(n) solution using a different approach? :)

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> sqr(n);
        int left = 0;
        int right = n -1;
        int index = n-1;
        while(left<=right)
        {
            int leftSqr = nums[left]*nums[left];
            int rightSqr = nums[right]*nums[right];
            if(leftSqr>rightSqr)
            {
                sqr[index--] = leftSqr;
                ++left;
            }else{
                sqr[index--] = rightSqr;
                --right;
            }
        }
        return sqr;
    }
};

std::ostream &operator<<(std::ostream &os, vector<int> vec)
{
    os << "[";
    for (int i = 0; i < vec.size(); ++i)
    {
        os << vec[i];
        if (i != vec.size() - 1)
        {
            os << ",";
        }
    }
    os << "]" << std::endl;
    return os;
}

int main()
{
    vector<int> num = {-2,-1,0,1,4};
    Solution sol;
    std::cout << sol.sortedSquares(num);
    return 0;
}