#include <iostream>
#include <unordered_map>
#include <unordered_set>
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

        std::unordered_map<char,char> mp;
        std::unordered_set<char> st;
        for(int i=0;i<s.size();++i){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]] != t[i]){return false;}
            }
            mp[s[i]] = t[i];
        }

        for(auto it=mp.begin();it!=mp.end();++it){
            st.insert(it->second);
        }
        if(st.size() != mp.size()){return false;}
        else {return true;}
    }
};

int main()
{
    Solution sol;
    std::cout << sol.isIsomorphic("badc", "baba");
    return 0;
}