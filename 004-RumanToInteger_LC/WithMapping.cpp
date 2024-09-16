#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
    public:
    int romanToInt(string s){
        unordered_map<char,int> mapp = {
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int pr_val = 0;
        int out = 0;
        for(int i =s.size()-1;i>=0;--i){
            char c = s[i];
            int cr_val = mapp[c];

            if(cr_val < pr_val){
                out -= cr_val;
            }
            else{
                out += cr_val; 
            }
            pr_val = cr_val;

        }
        return out;
    }

};

int main(){
    string s = "MCMXCIV";
    Solution sol;
    int out = sol.romanToInt(s);
    cout << out <<endl;
}