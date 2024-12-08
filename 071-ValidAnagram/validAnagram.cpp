#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.length() != t.length()){return false;}
        int size = s.size();
        int charArr[26] = {0};
        for (int i = 0; i < size; ++i)
        {
            ++charArr[((int)s[i]-'a')];
        }

        for(int i=0;i<size;++i)
        {
            --charArr[t[i]-'a'];
            if(charArr[t[i]-'a']<0)
            {
                return false;
            }
        }
        
        return true;
    }
};

int main()
{
    string s = "anagram";
    string t = "nagara";

    Solution sol;
    std::cout << sol.isAnagram(s, t);
}