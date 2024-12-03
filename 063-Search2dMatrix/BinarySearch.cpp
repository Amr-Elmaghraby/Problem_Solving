#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int columns = matrix[0].size();

        int left = 0, right = rows * columns - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int i = mid / columns, j = mid % columns;
            if (target == matrix[i][j])
                return true;
            else if(target<matrix[i][j])
                right = mid-1;
            else
                left = mid+1; 
        }

        return false;
    }
};

int main()
{

    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    Solution sol;
    bool res = sol.searchMatrix(matrix, 3);
    std::cout << res;
    return 0;
}