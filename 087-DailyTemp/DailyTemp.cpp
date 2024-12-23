#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution
{
    public:
    vector<int> dailyTemperatures(vector<int> &temperature)
    {
        size_t n = temperature.size();
        vector<int> waitDays(n,0);
        std::stack<int> stk;
        for(int i=0;i<n;++i)
        {
            while(!stk.empty()&&temperature[i]>temperature[stk.top()])
            {
                int indx = stk.top();
                stk.pop();
                waitDays[indx] = i - indx;
            }
            stk.push(i);
        }
        return waitDays;
    }
};

std::ostream& operator << (std::ostream &os,vector<int> vec){
    os<<"[";
    for(int i=0;i<vec.size();++i)
    {
        os<<vec[i];
        if(i != vec.size()-1){
            os<<",";
        }
    }
    os <<"]"<<std::endl;
    return os;
}

int main()
{
    vector<int> temp ={73,74,75,71,69,72,76,73};
    Solution sol;
    std::cout << sol.dailyTemperatures(temp);
    return 0;
}