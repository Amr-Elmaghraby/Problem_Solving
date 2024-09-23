#include <iostream>
#include <algorithm>
using namespace std;

int Mutual(int a , int b){
    int z = min(a,b);
    while(z){
        if( !(a%z) && !(a%z)){
            return z;
        }
        --z;
    }
    return 1;
}

int main(){
    int Y_W[2] = {0};
    cin >> Y_W[0] >> Y_W[1];
    int prob = 6 - max(Y_W[0],Y_W[1]) + 1;
    int Biggest_Mutual = Mutual(prob,6);
    cout << prob / Biggest_Mutual << '/' << 6 / Biggest_Mutual << endl; 

}