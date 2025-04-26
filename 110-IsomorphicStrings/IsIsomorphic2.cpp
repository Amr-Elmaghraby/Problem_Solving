#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        std::unordered_map<char, char> mapST, mapTS;

        for (int i = 0; i < s.size(); ++i)
        {
            char s_t = s[i];
            char t_s = t[i];

            if (mapST.count(s_t) && mapST[s_t] != t_s)
            {
                return false;
            }
            if (mapTS.count(t_s) && mapTS[t_s] != s_t)
            {
                return false;
            }

            mapST[s_t] = t_s;
            mapTS[t_s] = s_t;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.isIsomorphic("badc", "baba");
    return 0;
}