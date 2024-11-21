#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int majorityElement(vector<int>& nums){
        int balance = 0;
        int pivot = nums[0];
        for(int i=1;i<nums.size();++i){
            int current = nums[i];
            if(current == pivot){
                ++balance;
            }
            else{
                if(balance == 0){
                    pivot = current;
                }
                else{
                    -- balance;
                }
            }
        }
        return pivot;
    }
};


int main(){
    std::vector<int> x= {1,2,2,3,3,3,3,3,3,10,10,10,10};
    Solution s;
    int r = s.majorityElement(x);
    std::cout << r<<std::endl;
    return 0;
}
