#include <iostream>

using namespace std;

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    for(int i =0 ; i < s1.size() ; ++i){
        if( (int)s1[i] > 90){
            s1[i] -= 32;
        }
        if( (int)s2[i] > 90){
            s2[i] -= 32;
        } 
        if(s1[i] > s2[i]){
            cout << 1 <<endl;
            return 0;
        }
        else if (s1[i] < s2[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 0 << endl ;

}