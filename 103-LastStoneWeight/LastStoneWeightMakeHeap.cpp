#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones){
        std::make_heap(stones.begin(),stones.end());
        while(stones.size()>1){
            int y = stones.front();
            std::pop_heap(stones.begin(),stones.end());
            stones.pop_back();
            int x = stones.front();
            std::pop_heap(stones.begin(),stones.end());
            stones.pop_back();
            if(x!=y){
                stones.push_back(y-x);
                std::push_heap(stones.begin(),stones.end());
            }
        }
        return stones.empty()?0:stones[0];
    }
};

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    Solution sol;
    std::cout << sol.lastStoneWeight(stones);
    return 0;
}