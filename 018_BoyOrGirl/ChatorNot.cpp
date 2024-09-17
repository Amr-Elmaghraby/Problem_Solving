#include<iostream>
using namespace std;

// int main(){
//     string s;
//     cin >> s;
//     string out;
//     int flg=0;
//     out += s[0];
//     for(int i=1;i<s.size();++i){
//      for(int j=0;j<out.size();++j){
//        /* if(s[i]<91){
//          s[i] = s[i] +32;
//          }*/
//         if(s[i]==out[j]){
//             flg =1;
//         }
//      }
//      if(!flg){
//         out += s[i];
//      }
//      flg=0;   
//     }

//     if( out.size() % 2){
//         cout << "IGNORE HIM!" <<endl;
        
//     }
//     else{
//         cout << "CHAT WITH HER!"<<endl;
//     }
//     cout << out.size()<<endl;
// }

int main(){
    int distinct_char = 0;
    string s ;
    cin >> s;
    bool charPresent[26]={false};

    for(int i =0 ;i<s.size();++i){
        int index = s[i] - 'a';
        if(!charPresent[index]){
            charPresent[index] = true;
            distinct_char ++;
        }
    }

    if(distinct_char % 2){
        cout << "IGNORE HIM!" << endl;
    }
    else{
        cout << "CHAT WITH HER!" <<endl;
    }
    return 0;
}