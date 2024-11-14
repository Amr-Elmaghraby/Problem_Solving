#include <iostream>




int main(){
    bool arr[26] = {false};
    int num=0;
    while(1){
        char ch;
        std::cin >> ch;
        if(ch == '}') break;
        if(ch >='a' && ch<='z'){
            if(!arr[ch-'a']){
                arr[ch-'a'] = true;
                ++num;
            }
        }
    }

    std::cout << num;
    return 0;

}