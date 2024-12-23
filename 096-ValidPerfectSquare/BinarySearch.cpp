#include <iostream>
#include <vector>
using namespace std;


class Solution
{
    public:
    bool isPerfectSquare(int num){
        if(num<1){return false;}
        else if(num==1){return true;}
        
        int left = 1;
        int right = num/2; // No square root of a number greater than 1 will ever exceed half of it's value
        while(left<=right){
            int mid = left + (right-left)/2;
            // Avoid overflow by dividing before multiplying
            if(mid == num/mid){
                if(mid * mid == num){return true;}
                else{return false;}
            }else if(mid<num/mid){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        return false;

    }
};


int main(){
    int n = 44101;
    Solution sol;
    std::cout << sol.isPerfectSquare(n);
    return 0;
}