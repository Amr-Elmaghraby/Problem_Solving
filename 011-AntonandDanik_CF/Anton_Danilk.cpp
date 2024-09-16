#include <iostream>

using namespace std;


int main(){
    int num_of_games,Anton_d=0;
    cin >> num_of_games;
    char winner;
    for(int i =0 ;i < num_of_games ; ++i){
        cin >> winner;
        switch (winner){
            case 'A':
            Anton_d ++;
            break;
            case 'D':
            Anton_d --;
            break;
        }
    }
    if(Anton_d>0){
        cout << "Anton";
    }
    else if (Anton_d<0){
        cout << "Danik";
    }
    else{
        cout << "Friendship";
    }
}