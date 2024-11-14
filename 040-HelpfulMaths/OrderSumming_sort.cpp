#include <iostream>
#include <vector>
#include <algorithm>



int main(){
    std::string st;
    std::cin >> st;
    std::vector<int> nums;
    nums.reserve(10);
    for(char ch:st){
        if(ch!='+'){
            nums.push_back(ch-'0');
        }
    }

    std::sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();++i){
        if(i>0) std::cout << '+';
        std::cout<<nums[i];
    }

    return 0;
    
}