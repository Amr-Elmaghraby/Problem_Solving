#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Correct approach but time limit exceeded as Time complexity is O(nlog(n))
class Solution{
    public:
    int longestConsecutive(vector<int> &nums)
    {
        int longestSeq=0;
        std::set<int> st(nums.begin(),nums.end());

        int count = 1;
        int prev  = *st.begin();
        for(std::set<int>::iterator it=(++st.begin());it!=st.end();++it)
        {
            if( *(it) != (prev+1) )
            {
                longestSeq = count>longestSeq ? count:longestSeq;
                count = 0;
            }
            ++count;
            prev = *it;
        }
        if(count)
        {
            longestSeq = count>longestSeq ? count:longestSeq;
        }
        return longestSeq;
    }
};

int main()
{
    vector<int> vec = {1,2,3,4,5,7,8};
    Solution sol;
    int res = sol.longestConsecutive(vec);

    std::cout << res;

    return 0;
}