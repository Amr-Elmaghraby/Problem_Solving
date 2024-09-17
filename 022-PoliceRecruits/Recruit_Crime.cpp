#include<iostream>
using namespace std;


int main(){
    int num_of_events =0;
    cin >> num_of_events;

    int events[num_of_events] ={0};
    int available_officers=0,crimes=0;
    for(int i=0;i<num_of_events;++i){
        int tmp =0;
        cin >> tmp;
        if(tmp<0){
            if(available_officers ==0){
                crimes++;
            }else{
                available_officers--;
            }
        }else{
            available_officers += tmp; 
        }
    }
    cout << crimes << endl;

}