#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <string>
using namespace std;


class Solution {
    public:
    bool wordPattern(string pattern,string s){
        if(pattern.size()==0 || s.size()==0){return false;}
        std::vector<int> vec;

        //  THIS HASH IS NOT 100% SAFE FOR  e.g  "ad" and "db"
        int tmp=0;
        int weight = 2;
        for(char c:s){
            if(c != ' '){
                tmp += c*(weight++);
            }else{
                vec.push_back(tmp);
                tmp = 0;
                weight = 2;
            }
        }
        
        vec.push_back(tmp);
        if(pattern.size() != vec.size()){return false;}

        std::unordered_map<char,int> mapPV;
        std::unordered_map<int,char> mapVP;

        for(int i=0;i<pattern.size();++i){
            char P_V = pattern[i];
            int V_P = vec[i];

            if(mapPV.count(P_V) && mapPV[P_V] != V_P){
                return false;
            }

            if(mapVP.count(V_P) && mapVP[V_P] != P_V){
                return false;
            }

            mapPV[P_V] = V_P;
            mapVP[V_P] = P_V;
        }
        return true;
    }
};

int main(){
    Solution sol;
    std::cout << sol.wordPattern("hut","unit test harpoon");
    return 1;
}

