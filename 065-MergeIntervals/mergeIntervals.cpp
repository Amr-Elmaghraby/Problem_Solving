#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> merged;
        if (intervals.size() == 0 || intervals[0].size() != 2)
        {
            return merged;
        }
        if (intervals.size() == 1)
        {
            merged.push_back({intervals[0][0], intervals[0][1]});
            return merged;
        }

        // Sort vector if needed to only look for next node always
        std::sort(intervals.begin(), intervals.end());

        // array of two 
        // current[0]: to store first value of node
        // current[1]: to store last big value of nodes to be merged
        // ex. {{0,3},{2,5},{4,10}}  current[0] = 0, current[1] = 10 as to merge three node
        // to one node as to be {currnet[0],current[1]}
        int current[2] = {intervals[0][0], intervals[0][1]};
        for (int i = 1; i < intervals.size(); ++i)
        {
            // check if node is exceeding range to push prev nodes as one node merged
            if (intervals[i][0] > current[1])
            {
                merged.push_back({current[0], current[1]});
                // update current to be current node
                current[0] = intervals[i][0];
                current[1] = intervals[i][1];
                // decrease i as necessity to enter else in next loop
                --i;
            }
            else
            {
                // check if current node interval is not totally in prev range not to be neglected
                // ex.  {{0,4},{1,3}}, here we should just neglect {1,3}
                if (intervals[i][1] > current[1])
                {
                    current[1] = intervals[i][1];
                }
                // reaching last node just push last nodes values "IF last not pushed already
                //  in if condition above, as entering else in last loop means last node
                //   will not be pushed"
                if (i == intervals.size() - 1)
                {
                    merged.push_back({current[0], current[1]});
                }
            }
        }
        return merged;
    }
};

std::ostream &operator<<(std::ostream &os, vector<vector<int>> &vec)
{
    os << "[";
    for (int i = 0; i < vec.size(); ++i)
    {
        os << "[";
        for (int j = 0; j < vec[i].size(); ++j)
        {
            os << vec[i][j];
            if (j != vec[i].size() - 1)
            {
                os << ",";
            }
        }
        os << "]";
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
    vector<vector<int>> inter = {{1, 4}, {0, 2}, {3, 5}};
    Solution sol;
    vector<vector<int>> res = sol.merge(inter);
    std::cout << res;
    return 0;
}