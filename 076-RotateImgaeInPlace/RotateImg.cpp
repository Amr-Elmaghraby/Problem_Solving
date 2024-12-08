#include <iostream>
#include <vector>
using namespace std;
std::ostream &operator<<(std::ostream &os, vector<vector<int>> &mx);

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Transpose the matrix "make rows columns"
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                std::swap(matrix[i][j],matrix[j][i]);
            }
        }

        // Reverse each row
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<(n/2);++j)
            {
                std::swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }
        std::cout << matrix;
    }
};

std::ostream &operator<<(std::ostream &os, vector<vector<int>> &mx)
{
    os << "[";
    for (int i = 0; i < mx.size(); ++i)
    {
        os << "[";
        for (int j = 0; j < mx[0].size(); ++j)
        {
            os << mx[i][j];
            if (j != mx[0].size() - 1)
            {
                os << ",";
            }
        }
        os << "]";
        if (i != mx.size() - 1)
        {
            os << ",";
        }
    }
    os << "]";
    return os;
}

int main()
{
    // vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    Solution sol;
    sol.rotate(matrix);

    return 0;
}