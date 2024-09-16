#include<iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> output = {0, 0};
        short int size = nums.size();
        for (int i = 0; i < size-1; ++i) {
            for (int j = i+1; j < size; ++j) {
                if (nums[i] + nums[j] == target) {
                    output[0] = i;
                    output[1] = j;
                    return output;
                }
            }
        }
        return output;
    }
};

int main(){
    std::vector<int> arr = {1,2,3,7,8,10};
    Solution sol;
    std::vector<int> out = sol.twoSum(arr,11);
    std::cout << "[";
    for (size_t i = 0; i < out.size(); ++i) {
        std::cout << out[i];
        if (i != out.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}
