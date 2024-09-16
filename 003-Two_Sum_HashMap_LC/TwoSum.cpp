#include<iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map; // Maps number to its index
        std::vector<int> output;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                // If the complement is found, return the pair of indices
                output.push_back(num_map[complement]);
                output.push_back(i);
                return output;
            }
            // Store the index of the current number in the map
            num_map[nums[i]] = i;
        }
        return output; // This line is technically unreachable with valid input
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
