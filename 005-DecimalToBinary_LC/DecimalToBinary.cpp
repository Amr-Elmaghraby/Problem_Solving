#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    void isPalindrome(int x){
        int x_b=0;int factor=1;
        for(int i =0 ; i<=31;++i){
            x_b += factor * (x>>i & 1);
            factor *=10;
        }
        cout << x_b;
    }
};


int main(){
    Solution sol;
    int input = 121;
    sol.isPalindrome(input);

}
