#include <iostream>
#include <string>



int main(){
    int Pass_lenght,Distinct_Sym;
    std::cin >> Pass_lenght >> Distinct_Sym;
    if(Distinct_Sym < 1 || Distinct_Sym > 26 || Distinct_Sym > Pass_lenght){
        return 0;
    }
    std::string sr;
    sr.reserve(Pass_lenght);
    for(int i=0;i<Distinct_Sym;++i){
        sr.push_back('a'+i);
    }

    for(int i=0;i<(Pass_lenght-Distinct_Sym);++i){
        sr.push_back(sr[i]);
    }

    std::cout << sr << std::endl;

    return 0;
}