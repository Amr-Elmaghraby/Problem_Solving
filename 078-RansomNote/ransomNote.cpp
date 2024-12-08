#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


class Solution
{
    public:
    bool canConstruct(string ransomNote,string magazine)
    {
        std::unordered_map<char,int> map;
        for(char c:magazine){
            ++map[c];
        }

        for(char c:ransomNote)
        {
            if(map[c])
            {
                --map[c];
            }else{return false;}
        }
        return true;
    }
};

int main()
{
    string rn = "amraymanelmaghraby ";
    string mag = "amraymanelmaghraby";
    Solution sol;
    std::cout << sol.canConstruct(rn,mag);
    return 0;
}