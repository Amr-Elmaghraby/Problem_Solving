#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> productVec;
        int product = 1;
        bool zero = false;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                zero = true;
                continue;
            }
            product *= nums[i];
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (zero)
            {
                if (nums[i] == 0)
                {
                    productVec.push_back(product);
                }
                else
                {
                    productVec.push_back(0);
                }
            }
            else
            {
                productVec.push_back(product / nums[i]);
            }
        }

        return productVec;
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
    vector<int> nums = {1, 2, 0, 3, 0,4};
    Solution sol;
    vector<int> res = sol.productExceptSelf(nums);

    std::cout << res;

    return 0;
}