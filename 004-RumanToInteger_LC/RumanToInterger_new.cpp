#include <iostream>
#include <string>
#include <map>

class Solution{
    public:
    int romanToInt(std::string s)
    {
        std::map<char,int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int res = 0;
        for(int i=0; i< s.size();++i)
        {
            if( m[s[i]] < m[s[i+1]])
            {
                res += m[s[i+1]] - m[s[i]];
                ++i;
            }
            else
            {
                res += m[s[i]];
            }
        }
        return res;
    }
};



int main(){
    std::string s = "III";
    Solution sol;
    int res = sol.romanToInt(s);

    std::cout << res << std::endl;
    return 0;
}