#include <iostream>
#include <random>
#include <string>
#include <unordered_set>

int main()
{
    int Pass_Lenght, Distinct_Symbols;
    std::cin >> Pass_Lenght >> Distinct_Symbols;

    std::string sr;
    sr.reserve(Pass_Lenght);
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distr(0, 25);
    std::unordered_set<int> set;
    set.reserve(26);
    for (int i = 0; i < Distinct_Symbols; ++i)
    {
        int random_number = distr(rd);
        again:
        if ( set.find(random_number) == set.end() ){
            sr.push_back(random_number + 'a');
            set.insert(random_number);
        }else{
            random_number = (random_number+1)%26;
            goto again;
        }
    }
    for(int i=0;i<(Pass_Lenght - Distinct_Symbols );++i){
        sr.push_back(sr[i]);
    }

    std::cout << sr<<std::endl;

    return 0;
}