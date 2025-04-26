#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() ==0){return -1;}
        std::unordered_map<char,int> mp;
        
        for(char c:s){
            ++mp[c];
        }

        for(int i=0;i<s.size();++i){
            if(mp[s[i]] == 1){
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;
    std::cout << solution.firstUniqChar("loveleetcode");
    return 0;
}
