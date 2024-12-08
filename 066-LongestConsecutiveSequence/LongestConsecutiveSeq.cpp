#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Time Complexity is O(n)
// Space Complexity is O(n)

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int LongestSeq = 0;
        std::unordered_set<int> set(nums.begin(), nums.end());
        int tmp_count = 0;
        for (int num : nums)
        {
            if (!set.count(num - 1))
            {
                tmp_count = 0;
                while (set.count(num))
                {
                    ++num;
                    ++tmp_count;
                }
                LongestSeq = tmp_count > LongestSeq ? tmp_count : LongestSeq;
            }
        }

        return LongestSeq;
    }
};

int main()
{
    vector<int> vec = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    Solution sol;
    int res = sol.longestConsecutive(vec);

    std::cout << res;

    return 0;
}