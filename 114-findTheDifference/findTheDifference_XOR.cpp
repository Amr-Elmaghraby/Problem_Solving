#include <iostream>
using namespace std;

class Solution{
    public:
    char findTheDifference(string s,string t){
        if(t.size()<s.size()){return ' ';}

        char res =0;

        for(char c:s){
            res ^= c;
        }

        for(char c:t){
            res ^=c;
        }

        return res;
    }
};



int main(){
    Solution sol;
    // std::cout << sol.findTheDifference("abcd","abcde");
    std::cout << sol.findTheDifference("a","aa");
}