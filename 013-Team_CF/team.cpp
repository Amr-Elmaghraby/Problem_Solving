#include <iostream>
using namespace std;


int main(){
    int n , total_prob=0;
    cin >>n;
    char Team_Knowledge[n]={0};
    bool temp = 0;
    for(int j=0;j<n;j++){
        for(int i =0;i< 3;++i){
            cin >> temp;
            Team_Knowledge[j] += (int)temp;
        }
    }
    for(int i : Team_Knowledge){
        if(i >= 2){
            total_prob ++;
        }
    }

    cout << total_prob << endl;
}