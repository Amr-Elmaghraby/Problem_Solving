#include <iostream>
 
using namespace std;
 
void get_index(int * row , int * column){
    int temp=0;
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            cin >> temp;
            if(temp==1){
                *column = j;
                *row = i;
                return ;
            }
        }
    }
}
 
int main(){
    int row=0,column=0,move=0;
    get_index(&row,&column);
    
    move = (2-row);
    if(move <0){move = -move;}
    if((2-column)>=0){
        move += (2-column);
    }
    else{
        move -= (2-column);
    }
 
    cout << move << endl;
}