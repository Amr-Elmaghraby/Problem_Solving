#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int insertPos = 0;
        for(int num:nums){
            if(num != 0){
                nums[insertPos++] = num;
            }
        }
        
        while(insertPos < nums.size()){
            nums[insertPos++] = 0;
        }
    }
};

std::ostream& operator << (std::ostream & os , vector<int>& num){
    os << "[";
    for(int i=0;i<num.size();++i){
        os << num[i];
        if(i!=num.size()-1){
            os << ",";
        }
    }
    os<<"]";
    return os;
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution sol;
    sol.movezeroes(nums);
    std::cout << nums;
    return 0;
}