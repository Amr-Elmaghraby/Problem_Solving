#include <iostream>



int main(){
    int num_of_lines =0;
    long long int IceCream =0;
    long int distressed=0;
    std::cin >> num_of_lines >> IceCream;
    for(int i=0;i<num_of_lines;++i){
        char sign;
        long long int tmp=0;
        std::cin >> sign >> tmp;
        if(sign == '+'){
            IceCream += tmp;
        }
        else{
            if( (IceCream - tmp) < 0){
                ++distressed; 
            }
            else{
                IceCream -= tmp;
            }
        }
    }

    std::cout << IceCream << ' ' << distressed <<std::endl;

    return 0;
}
