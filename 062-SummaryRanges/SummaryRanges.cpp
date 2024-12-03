#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> str;
        if (nums.size() == 0)
        {
            return str;
        }
        // Start of the current range
        int start = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            // Check if the current number is not consecutive
            if (nums[i] != nums[i - 1] + 1)
            {
                string tmp = std::to_string(start);
                if(start != nums[i-1])
                {
                    tmp += "->";
                    tmp += std::to_string(nums[i-1]);
                }
                str.push_back(tmp);
                // Update start to the new range
                start = nums[i];
            }
        }
        // Add the last range
        if(start == nums[nums.size()-1])
        {
            str.push_back(std::to_string(start));
        }
        else
        {
            string tmp = std::to_string(start)+"->"+std::to_string(nums[nums.size()-1]);
            str.push_back(tmp);
        }

        return str;
    }
};

std::ostream &operator<<(std::ostream &os, vector<string> &st)
{
    os << "[";
    for (int i = 0; i < st.size(); ++i)
    {
        os << "\"";
        os << st[i];
        os << "\"";
        if (i != st.size() - 1)
        {
            os << ",";
        }
    }
    os << "]" << std::endl;
    return os;
}

int main()
{
    vector<int> nums = {};
    for(int i=0;i<1000;++i)
    {
        if(!(i%100))
        {
            ++i;
        }
        nums.push_back(i);
    }
    Solution sol;
    vector<string> st = sol.summaryRanges(nums);

    std::cout << st;
    return 0;
}