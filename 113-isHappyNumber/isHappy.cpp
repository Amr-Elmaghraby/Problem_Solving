#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

class Solution{
    public:
    bool isHappy(int n){
        std::unordered_set<long long 
        int> st;
        long long int nn = n;
        while( nn!=1 && !st.count(nn)){
            st.insert(nn);
            long long nxt = 0;
            while(nn>0){
                int digit = nn%10;
                nxt += digit*digit;
                nn /= 10; 
            }
            nn =nxt;
        }

        return nn == 1;
    }
};


int main(){
    Solution sol;
    std::cout << sol.isHappy(2);
    return 0;
}