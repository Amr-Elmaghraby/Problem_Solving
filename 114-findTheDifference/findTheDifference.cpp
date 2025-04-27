#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

class Solution{
    public:
    char findTheDifference(string s,string t){
        if(t.size()<s.size()){return ' ';}

        std::unordered_map<char,int> mp;

        for(char c:s){
            ++mp[c];
        }

        for(char c:t){
            if(mp[c] !=0){
                --mp[c];
            }else{return c;}
        }

        return ' ';
    }
};



int main(){
    Solution sol;
    // std::cout << sol.findTheDifference("abcd","abcde");
    std::cout << sol.findTheDifference("a","aa");
}