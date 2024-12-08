#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int outerElements(vector<vector<int>> &matrix, vector<int> &spiral, int prev_last)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int OuterElements;
        if (n == 1 || m == 1)
        {
            OuterElements = m != 1 ? m : n;
        }
        else if ((2 * n + 2 * (m - 2)) == 0)
        {
            OuterElements = 1;
        }
        else
        {
            OuterElements = 2 * n + 2 * (m - 2);
        }
        int i = 0;
        int j = 0;
        bool still = true;
        for (int indx = 0; indx < OuterElements; ++indx)
        {
            spiral[indx + prev_last] = matrix[i][j];
            matrix[i].erase(matrix[i].begin() + j);
            if (matrix[i].size() == 0)
            {
                matrix.erase(matrix.begin() + i);
                --i;
                if (indx != 0)
                {
                    still = true;
                }
            }
            if (indx >= m - 1)
            {
                if (indx >= n + m - 2)
                {
                    if (j == 0)
                    {
                        if (i == 0)
                        {
                            return (indx + prev_last);
                        }
                        else
                        {
                            if (still)
                            {
                                still = false;
                                continue;
                            }
                            else
                            {
                                --i;
                            };
                        }
                    }
                    else
                    {
                        --j;
                    }
                }
                else
                {
                    j = m - 1;
                    ++i;
                }
            }
        }
        return 0;
    }
    vector<int> spiralMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int prev_lst = 0;
        vector<int> spiral(n * m, 0);
        while (matrix.size())
        {
            prev_lst = outerElements(matrix, spiral, prev_lst);
            ++prev_lst;
        }
        return spiral;
    }
};

std::ostream &operator<<(std::ostream &os, vector<int> &vec)
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
    os << "]";
    return os;
}

int main()
{
    // vector<vector<int>> mx = {{1, 2, 3,4}, {5, 6,7,8}, { 9,10,11,12},{ 13,14,15,16},{17,18,19,20}};
    vector<vector<int>> mx = {{1, 11}, { 2, 12 }, { 3, 13 }, { 4, 14 }, { 5, 15 }, { 6, 16 }, { 7, 17 }, { 8, 18 }, { 9, 19 }, { 10, 20 }};
    Solution sol;
    vector<int> res = sol.spiralMatrix(mx);

    std::cout << res;
    return 0;
}