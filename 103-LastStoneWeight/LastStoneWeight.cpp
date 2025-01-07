#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        int n = stones.size();
        if (n == 0)
        {
            return 0;
        }
        std::sort(stones.begin(), stones.end());
        for (int i = n - 1; i > 0; --i)
        {
            stones[i - 1] = stones[i] - stones[i - 1];
            stones.pop_back();
            std::sort(stones.begin(), stones.end());
        }

        return stones[0];
    }
};

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    Solution sol;
    std::cout << sol.lastStoneWeight(stones);
    return 0;
}