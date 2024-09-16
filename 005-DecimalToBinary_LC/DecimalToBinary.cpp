#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    bool isPalindrome(int x){
        bool out = true;
        int x_b=0;int factor=1;
        for(int i =0 ; i<=31;++i){
            x_b += factor * (x>>i & 1);
            factor *=10;
        }
        cout << x_b;
        return out;
    }
};


int main(){
    Solution sol;
    int input = 121;
    bool out = sol.isPalindrome(input);


    // cout << out << endl;
}