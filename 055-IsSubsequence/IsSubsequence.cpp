#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i=0,j=0;
        while(i<s.size() && j<t.size())
        {
            if(s[i] == t[j])
            {
                ++i;
            }
            ++j;
        }
        return i==s.size();
    }
};

int main()
{
    string t = "ahbgdc";
    string s = "abc";
    Solution sol;
    bool res = sol.isSubsequence(s, t);

    std::cout << res;
    return 0;
}