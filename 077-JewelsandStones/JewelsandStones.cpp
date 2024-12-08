#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution
{
    public:
    int numJewelsInStones(string jewels,string stones){
        int num =0;
        std::unordered_set<char> set(jewels.begin(),jewels.end());
        for(char stone:stones)
        {
            if(set.count(stone))
            {
                ++num;
            }
        }
        return num;
    }
};


int main()
{
    string j = "aA";
    string s = "aAAbbbbb";
    Solution sol;
    std::cout << sol.numJewelsInStones(j,s);
    return 0;
}