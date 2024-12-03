#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> productVec;
        // Calculate prefix products
        int prefix = 1;
        for(int i=0;i<nums.size();++i)
        {
            productVec.push_back(prefix);
            prefix *=nums[i]; 
        }

        // Calculate suffix products
        int suffix = 1;
        for(int i=nums.size()-1;i>=0;--i)
        {
            productVec[i] *= suffix;
            suffix *= nums[i];
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
    vector<int> nums = {1, 2,0,3,4};
    Solution sol;
    vector<int> res = sol.productExceptSelf(nums);

    std::cout << res;
    return 0;
}