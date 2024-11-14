#include <iostream>
#include <string>



int main(){
    int word_num=0;
    std::cin >> word_num;
    for(int i=0;i<word_num;++i){
        std::string st;
        int word_length =0;
        std::cin >> st;
        if(st.size() > 10){
            std::cout << st[0] << st.size() - 2 << st.back() <<std::endl;
        }
        else{
            std::cout << st << std::endl;
        }
    }

    return 0;
}