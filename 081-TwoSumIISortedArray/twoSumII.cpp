#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ind(2);

        int left = 0;
        int right = numbers.size() - 1;
        while (left <= right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum > target)
            {
                --right;
            }
            else if (sum < target)
            {
                ++left;
            }
            else
            {
                ind[0] = ++left;
                ind[1] = ++right;
                return ind;
            }
        }
        return ind;
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
    vector<int> nums = {2, 7, 11, 15};

    int target = 9;
    Solution sol;
    std::cout << sol.twoSum(nums, target);
    return 0;
}