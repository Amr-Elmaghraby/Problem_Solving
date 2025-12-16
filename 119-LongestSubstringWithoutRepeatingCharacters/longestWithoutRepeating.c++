#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char,int> lastIndex;
        int max_length = 0;
        int substring_start_index = 0;
        int start = 0; // start of substring
        for(int i=0;i<s.size();++i)
        {
            if( lastIndex.find(s[i]) != lastIndex.end() && lastIndex[s[i]] >=start)
            {
                start = lastIndex[s[i]] + 1;
            }

            lastIndex[s[i]] = i; //update last index of any character;
            max_length = std::max(max_length,i - start + 1); // update value of max_length
        }

        return max_length;
    }
};

int main()
{
    string s = "qwertyuiopasdfghjkl;zxcmbbmvcxb.]erkadf;flelfpl1230904;ad.v//aflkaec,";
    Solution sol;
    std::cout << sol.lengthOfLongestSubstring(s);
    return 0;
}