#include <iostream>
#include <vector>
using namespace std;


class Soltuion
{
    public:
    bool searchMatrix(vector<vector<int>> &matrix,int target)
    {
        int i;
        for(i=0;i<matrix.size();++i)
        {
            if(matrix[i][0]>target)
            {
                if(matrix[i][0]==target)
                {
                    return true;
                }
                break;
            }
        }
        if(i==0){return false;}
        --i;
        for(int j=0;j<matrix[0].size();++j)
        {
            if(matrix[i][j] == target)
            {
                return true;
            }
        }
        return false;

    }
};


int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    Soltuion sol;
    bool res= sol.searchMatrix(matrix,3);

    std::cout << res;

    return 0;
}