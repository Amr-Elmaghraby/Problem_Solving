#include <iostream>
#include <vector>
#include <unordered_set>

//0r best practical solution
class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        //check if board size is zero
        if (!board.size())
        {
            return false;
        }
        // vector of sets of columns and block as needed to store previous values
        // no need for rows_set to be vector as iteration is on rows so no need 
        // to store previous values of previous iteration
        std::vector<std::unordered_set<char>> block_set(board.size());
        std::vector<std::unordered_set<char>> columns_set(board.size());

        //outer loop of rows and inner of columns to iterate throw each rows atime  
        for (int i = 0; i < board.size(); ++i)
        {
            //rows_set to store row elements of each iteration
            std::unordered_set<char> rows_set;
            for (int j = 0; j < board[0].size(); ++j)
            {
                //variable to store current element value
                char num = board[i][j];
                //if it's empty then just continue
                if (num == '.')
                    continue;

                //check if current element is already in the rows_set
                // returning flase if found and inserting it if not
                if (rows_set.count(num))
                    return false;
                else
                    rows_set.insert(num);

                //same check for columns with right implementation for each element to
                // to be stored in the right set number     
                if (columns_set[j].count(num))
                    return false;
                else
                    columns_set[j].insert(num);

                //calculating correct block_set index to store the current value in
                int index = (i / 3) * 3 + (j / 3);

                //same check as columns_set ofr block_set
                if (block_set[index].count(num))
                    return false;
                else
                    block_set[index].insert(num);
            }
        }
        //returning true at the end if no element is found to be invalid in it's position
        return true;
    }
};

std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<char>> &vc)
{
    int rows = vc.size();
    int columns = (rows) ? columns = vc[0].size() : 0;
    os << "[";
    for (int i = 0; i < rows; ++i)
    {
        os << "[";
        for (int j = 0; j < columns; ++j)
        {
            os << "\"";
            os << vc[i][j];
            os << "\"";
            if (j < (columns - 1))
            {
                os << ",";
            }
        }
        os << "]";
        if (i < (rows - 1))
        {
            os << std::endl;
            os << ",";
        }
    }
    os << "]" << std::endl;
    return os;
}

int main()
{
    // std::vector<std::vector<char>> br = {
    //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, // 1
    //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, // 2
    //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, // 3

    //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, // 4
    //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, // 5
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, // 6

    //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, // 7
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, // 8
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}, // 9
    // };
    std::vector<std::vector<char>> br = {
        {'.', '.', '.',     '.', '.', '.',   '5', '.', '.'},
        {'.', '.', '.',     '.', '.', '.',   '.', '.', '.'},
        {'.', '.', '.',     '.', '.', '.',   '.', '.', '.'},

        {'9', '3', '.',     '.', '2', '.',   '4', '.', '.'},
        {'.', '.', '7',     '.', '.', '.',   '3', '.', '.'},
        {'.', '.', '.',     '.', '.', '.',   '.', '.', '.'},

        {'.', '.', '.',     '3', '4', '.',   '.', '.', '.'},
        {'.', '.', '.',     '.', '.', '3',   '.', '.', '.'},
        {'.', '.', '.',     '.', '.', '5',   '2', '.', '.'}};
    Solution sl;
    bool res = sl.isValidSudoku(br);

    std::cout << br;

    std::cout << res;

    return 0;
}