#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
    public:
    bool containsDuplicate(vector<int>& nums){
        std::unordered_set<int> seen;
        seen.reserve(30);
        for(int num : nums){
            if(seen.find(num) != seen.end()){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};


int main(){
    vector<int> nums;
    Solution sol;
    while(1){
        int tmp;
        cin>>tmp;
        if(cin.fail()){
            cin.clear();
            char ch;
            cin >> ch;
            if(ch==']'){
                break;
            }
            continue;
        }
        nums.push_back(tmp);
    }
    bool res = sol.containsDuplicate(nums);
    std::cout << res;
    return 0;
}