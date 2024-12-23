#include <iostream>
#include <vector>
using namespace std;


class Solution
{
    public:
    int mySqrt(int x){
        if(x<2){return 0;}
        int left = 1;
        int right = x/2; // as sqrt wouldn't be larger than half of value
        while(left<right)
        {
            int mid = left+(right-left)/2;
            // make it division rather than multiplication to avoid overflow 
            if(mid == x/mid)
            {
                return mid;
            }else if(mid >=x/mid)
            {
                right = mid-1;
            }else
            {
                left = mid+1;
            }
        }
        return right; 
    }
};

int main()
{
    int x = 94532;
    Solution sol;
    std::cout << sol.mySqrt(x);
    return 0;
}