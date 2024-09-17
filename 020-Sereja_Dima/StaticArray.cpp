#include <iostream>
using namespace std;


int main(){
    int num_of_cards=0;
    cin >> num_of_cards;
    int cards[num_of_cards];
    for(int i=0;i<num_of_cards;++i){
        cin >> cards[i];
    }
    int head=0,tail=num_of_cards-1;
    int Sereja_pt=0,Dima_pt=0;
    for(int i=0;i<num_of_cards;++i){
        int tmp=0;
        if(cards[head] >= cards[tail]){
            tmp = cards[head];head++;
        }
        else{
            tmp = cards[tail];tail--;
        }
        if(i%2){
            Dima_pt += tmp;
        }
        else{
            Sereja_pt += tmp;
        }
    }

    cout << Sereja_pt << ' ' << Dima_pt << endl;
}