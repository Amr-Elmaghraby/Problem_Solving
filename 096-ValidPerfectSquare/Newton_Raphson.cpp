#include <iostream>
#include <vector>
using namespace std;


class Solution
{
    public:
    bool isPerfectSquare(int num){
        if(num<1){return false;}
        else if (num==1){return true;}
        
        // Newton-Raphson method
        int guess = num/2;
        while(guess>num/guess){
            guess = (guess+num/guess)/2;
        }

        return guess * guess == num;
    }
};


int main(){
    int n = 44100;
    Solution sol;
    std::cout << sol.isPerfectSquare(n);
    return 0;
}