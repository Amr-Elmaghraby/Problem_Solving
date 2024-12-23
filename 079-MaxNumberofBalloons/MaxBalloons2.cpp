#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
    public:
    int maxNumberOfBalloons(string text){
        int maxPoss = text.size()/7;
        if(!maxPoss){return 0;}
        static const std::unordered_map<char,int> ballonFreq={{'b',1},{'a',1},{'l',2},{'o',2},{'n',1}};

        std::unordered_map<char,int> textFreq;
        for(char c:text){
            ++textFreq[c];
        }

        for(auto&[charB,freqB]:ballonFreq){
            maxPoss = std::min(maxPoss,textFreq[charB]/freqB);
        }

        return maxPoss;
    }
};


int main()
{
    string str = "loonbalxballpoon";
    Solution sol;
    std::cout << sol.maxNumberOfBalloons(str);
    return 0;
}