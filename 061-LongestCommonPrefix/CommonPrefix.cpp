#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        string str = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            for (int j = 0; j < strs[i].size(); ++j)
            {
                if (str[j] != strs[i][j])
                {
                    while (str.size() > j )
                    {
                        str.pop_back();
                    }
                    break;
                }
            }
            while (str.size() > strs[i].size())
            {
                str.pop_back();
            }
            if(str.empty()){return "";}
        }
        return str;
    }
};

int main()
{
    vector<string> str = {};
    Solution sol;
    string res = sol.longestCommonPrefix(str);
    std::cout << res;

    return 0;
}