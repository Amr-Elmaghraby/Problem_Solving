#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class Solution{
    public:
    bool isValid(string s){
        stack<char> st;
        for(size_t i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else if(st.empty()){
                return false;
            }
            else{
                if( (st.top()=='(' && s[i]==')') || (st.top()=='{' && s[i]=='}') || (st.top()=='[' && s[i]==']') ){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }else{
         return false;
        }
    }
};

int main(){
    Solution sol;
    bool out = sol.isValid("[]");
    cout << out <<endl;
}