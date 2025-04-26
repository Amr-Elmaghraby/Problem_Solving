#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;


class Solution {
    public:
    bool wordPattern(string pattern,string s){
        if(pattern.size()==0 || s.size()==0){return false;}
        std::istringstream iss(s);
        std::vector<string> words;
        std::string word;
        while( iss >> word){
            words.push_back(word);
        }
        
        if(pattern.size() != words.size()){return false;}

        std::unordered_map<char,std::string> mapPW;
        std::unordered_map<std::string,char> mapWP;

        for(int i=0;i<pattern.size();++i){
            char P_W = pattern[i];
            std::string W_P = words[i];

            if(mapPW.count(P_W) && mapPW[P_W] != W_P){
                return false;
            }

            if(mapWP.count(W_P) && mapWP[W_P] != P_W){
                return false;
            }

            mapPW[P_W] = W_P;
            mapWP[W_P] = P_W;
        }
        return true;
    }
};

int main(){
    Solution sol;
    std::cout << sol.wordPattern("hut","unit test harpoon");
    return 1;
}

