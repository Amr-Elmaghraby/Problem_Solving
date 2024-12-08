#include <iostream>
#include <vector>
using namespace std;


class Solution{
    public:
    vector<int> spiralMatrix(vector<vector<int>> &matrix){
        std::vector<int> spiral;
        if(matrix.empty()){return spiral;}
        
        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;

        while(top<=bottom &&  left<=right)
        {
            // Traverse from left to right across top row
            for(int col=left;col<=right;++col){
                spiral.push_back(matrix[top][col]);
            }
            ++top;

            // Traverse from top to bottom along right column
            for(int row = top;row<=bottom;++row){
                spiral.push_back(matrix[row][right]);
            }
            --right;

            if(top<=bottom){
                // Traverse form right to left across bottom row
                for(int col=right;col>=left;--col){
                    spiral.push_back(matrix[bottom][col]);
                }
                --bottom;
            }

            if(left<=right){
                // Traverse from bottom to top along top left column
                for(int row=bottom;row>=top;--row){
                    spiral.push_back(matrix[row][left]);
                }
                ++left;
            }
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

int main(){
    vector<vector<int>> mx = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    Solution sol;
    vector<int> res = sol.spiralMatrix(mx);
    std::cout << res;
    return 0;
}