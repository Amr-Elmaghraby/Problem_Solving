#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
#include <string>

    
class Solution{
    public:
    int firstUnique(string s){
        if(s.size() ==0 ){return -1;}
        std::unordered_map<char,int> mp;
        std::set<int> st;

        for(int i=0;i<s.size();++i){
            if(mp.count(s[i])){
                st.erase(mp[s[i]]);
            }else{
                mp[s[i]] = i;
                st.insert(i);
            }
        }

        return st.empty()? -1:*st.begin();
    }
};


int main(){
    Solution sol;
    std::cout << sol.firstUnique("loveleetcode");
    return 0;
}