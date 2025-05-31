#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution{
    public:
    vector<string> fizzBuzz(int n){
        std::vector<string> out ;
        out.reserve(10);
        if(n<1){return out;}
        for(int i=1;i<=n;++i){
            if(i%15 ==0){
                out.push_back("FizzBuzz");
            }else if(i%3==0){
                out.push_back("Fizz");
            }else if(i%5 ==0){
                out.push_back("Buzz");
            }else{
                out.push_back(to_string(i));
            }
        }
        return out;
    }
};


std::ostream & operator << (std::ostream & os, std::vector<string> st)
{
    if(st.size() ==0){return os;}
    os << "[";
    for(int i=0;i<st.size();++i){
        os << "\"";
        os << st[i];
        os << "\"";
        if(i != st.size() -1)
            os << ",";
    }
    os<< "]";
    return os;
}



int main()
{
    Solution sol;
    std::cout << sol.fizzBuzz(15);
    return 0;
}