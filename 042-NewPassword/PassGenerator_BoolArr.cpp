#include <iostream>
#include <random>
#include <string>



int main(){
    int Pass_Lenght,Distinct_Sym;
    std::cin >> Pass_Lenght >> Distinct_Sym;
    if(Distinct_Sym < 1 || Distinct_Sym > 26){
        return 0;
    }
    bool letters[26] = {0};
    std::string sr;
    sr.reserve(Pass_Lenght);
    std::random_device dev;
    std::mt19937 gen(dev());
    std::uniform_int_distribution<> distr(0,25);

    for(int i=0;i<Distinct_Sym;++i){
        int random_number = distr(dev);
        retry:
        if(!letters[random_number]){
            sr.push_back(random_number + 'a');
            letters[random_number] = true;
        }
        else
        {
            random_number = (random_number + 1) % 26;
            goto retry;
        }
    }

    for(int i=0;i<Pass_Lenght - Distinct_Sym;++i){
        sr.push_back(sr[i]);
    }

    std::cout << sr << std::endl;

    return 0;
}