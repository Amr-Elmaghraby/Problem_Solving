#include<iostream>

using namespace std;

int main(){
    int number_of_strips=4;
    int TOT_Calories=0;
    int Val_of_Cal[number_of_strips];
    for(int i=0;i<number_of_strips;++i){
        cin >> Val_of_Cal[i];
    }
    string s ;
    cin >> s;
    for(char c:s){
        int index = c - '1';
        TOT_Calories += Val_of_Cal[index];
    }
    cout << TOT_Calories << endl;

}