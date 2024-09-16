#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution{
    public:
    bool isPalindrome(int x){
        if(x<0){
            return false;
        }//else if (x==0){
        //     return true;
        // }
        int base =  1;
        while( (x/base) >= 10){
            base*=10;
        }
        while(x>0){
            int left = x/base;
            int right = x % 10;
            if(right != left ){
                return false;
            }
            x = (x % base) / 10;
            base /=100; 
        }
        return true;

        // int val = x;
        // while(x >0){
        //     base ++;
        //     val /=10;
        // }
        // int loop = base/2 ;
        // for(int i=0 ; i<= loop;i++){
        //     int up_po = pow(10,base-1);
        //     int low_po = pow(10,i);
        //     int up_num = ( x / up_po )% 10;
        //     int low_num = ( x / low_po ) % 10;
        //     cout << up_num << "----" << low_num << endl;
        //     if( up_num != low_num  ){
        //         return false;
        //         }
        //     base--;
        // }
    }
};


int main(){
    Solution sol;
    int input = 0;
    bool out = sol.isPalindrome(input);


    cout << out << endl;
}