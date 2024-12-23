#include <iostream>



class Solution{
    public:
    int mySqrt(int x){

        // Bit Manipulation to get log_2(X)
        int copyX = x;
        int bitLength = 0;
        while(copyX)
        {
            ++bitLength;
            copyX >>=1;
        }
        --bitLength;

        // first guess to be half of bitlenght  
        int guess = 1L<<(bitLength/2);

        //  Newton Raphson method to get closer to the real sqrt value
        // X_new = X_old - [ f(x)/f'(x) ]
        // as to get sqrt of a value 'a' ===> f(x) = x^2 - a , f'(x) = 2x
        // So x_new = x_old - [(x_old^2 +a )/(2x_old)]
        // x_new = ( x_old(2x_old) - x_old^2 +a ) / 2x_old , divide nominator and denominator by x_old
        // x_new = (x_old + (a/x_old)) / 2

        for(int i=0;i<4;++i)
        {
            guess = (guess+(x/guess))/2;
        }
        return guess;
    }
};


int main()
{
    int x = 49;
    Solution sol;
    std::cout << sol.mySqrt(x);
    return 0;
}