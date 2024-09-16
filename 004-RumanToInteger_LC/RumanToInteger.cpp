#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int int_out=0,lst=0,crt=0;
        for(int i = s.size() -1 ; i>=0;--i){
        //OR Make for loop from 0 to c.size()-1 
        // making condition if crt < lst 
        // int_out -= crt - 2*lst 
            lst = crt ;
            switch( s[i] ){
                case 'I':
                crt = 1;
                break;
                case 'V':
                crt = 5;
                break;
                case 'X':
                crt = 10;
                break;
                case 'L':
                crt = 50;
                break;
                case 'C':
                crt =100;
                break;
                case 'D':
                crt =500;
                break;
                case 'M':
                crt =1000;
                break;
            }
            if( lst > crt){
                int_out -= crt;
            }
            else{
                int_out += crt ;
            }

        }
        return int_out;
    }
};

int main(){
    Solution sol;
    string s = "MCMXCIV";
    int out = sol.romanToInt(s);
    cout << out<<endl;
}