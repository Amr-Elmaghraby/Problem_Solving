#include <iostream>
#include <vector>
#include <unordered_set>



//0r not best practical solution
class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        int rows = board.size();
        int columns = 0;
        if (rows)
            columns = board[0].size();
        else
            return false;

        int st = 0;
        while (st < rows)
        {
            std::unordered_set<char> rows_set;
            std::unordered_set<char> columns_set;
            std::unordered_set<char> block_set;
            for (int j = 0; j < columns; ++j)
            {
                if (board[st][j] == '.')
                {
                    continue;
                }
                if (rows_set.find(board[st][j]) != rows_set.end())
                {
                    return false;
                }
                else
                {
                    rows_set.insert(board[st][j]);
                }
            }
            for (int i = 0; i < rows; ++i)
            {
                if (board[i][st] == '.')
                {
                    continue;
                }
                if (columns_set.find(board[i][st]) != columns_set.end())
                {
                    return false;
                }
                else
                {
                    columns_set.insert(board[i][st]);
                }
            }
            for (int i = (st/3)*3; i < (st/3)*3 + 3; ++i)
            {
                for (int j = (st * 3) % 9; j < ((st * 3) % 9 + 3); ++j)
                {
                    if (board[i][j] == '.')
                    {
                        continue;
                    }
                    if (block_set.find(board[i][j]) != block_set.end())
                    {
                        return false;
                    }
                    else
                    {
                        block_set.insert(board[i][j]);
                    }
                }
            }
            ++st;
        }
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
    std::vector<std::vector<char>> br = {
        {'5', '3', '.',     '.', '7', '.',   '.', '.', '.'}, // 1
        {'6', '.', '.',     '1', '9', '5',   '.', '.', '.'}, // 2
        {'.', '9', '8',     '.', '.', '.',   '.', '6', '.'}, // 3

        {'8', '.', '.',     '.', '6', '.',   '.', '.', '3'}, // 4
        {'4', '.', '.',     '8', '.', '3',   '.', '.', '1'}, // 5
        {'7', '.', '.',     '.', '2', '.',   '.', '.', '6'}, // 6

        {'.', '6', '.',     '.', '.', '.',   '2', '8', '.'}, // 7
        {'.', '.', '.',     '4', '1', '9',   '.', '.', '5'}, // 8
        {'.', '.', '.',     '.', '8', '.',   '.', '7', '9'}, // 9
    };
    Solution sl;
    bool res = sl.isValidSudoku(br);

    std::cout << br;

    std::cout << res;

    return 0;
}