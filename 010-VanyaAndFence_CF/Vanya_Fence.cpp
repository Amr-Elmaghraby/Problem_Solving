#include<iostream>

using namespace std;


int main(){
    int fence_h,friends_num,width,tot_width=0;
    cin >> friends_num ; 
    cin >> fence_h;
    for(int i =0 ; i < friends_num ; ++i){
        cin >> width;
        if( width > fence_h ){
            tot_width += 2;
        }
        else{
            tot_width ++ ;
        }
    }
    cout << tot_width <<endl;
}