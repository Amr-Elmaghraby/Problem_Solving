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
            int j=0;
            // Compare character on by one
            while(j<str.size()&&j<strs[i].size()&&str[j]==strs[i][j])
            {
                ++j;
            }
            // Update prefix to the common part
            str = str.substr(0,j);

            // If prefix becomes emtpy, return immediately
            if(str.empty()){return "";}
        }
        return str;
    }
};

int main()
{
    vector<string> str = {"flower","flow","flight","a"};
    Solution sol;
    string res = sol.longestCommonPrefix(str);
    std::cout << res;

    return 0;
}