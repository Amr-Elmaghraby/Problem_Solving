#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        if (piles.size() == 0)
        {
            return 0;
        }
        int n = piles.size();
        int left = 1;
        int right = *std::max(piles.begin(), piles.end());
        int res = right;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int tmp_h = 0;
            for (int p : piles)
            {
                tmp_h += (p / mid);
                if (p % mid)
                {
                    ++tmp_h;
                }
                if (tmp_h > h)
                {
                    left = mid + 1;
                    break;
                }
            }
            if (tmp_h <= h)
            {
                res = mid;
                right = mid - 1;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    Solution sol;
    std::cout << sol.minEatingSpeed(piles, h);
    return 0;
}