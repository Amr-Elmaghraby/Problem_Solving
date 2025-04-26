#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution{
    public:
    vector<int> intersection(vector<int>&nums1, vector<int>& nums2){
        vector<int> out;
        out.reserve( (nums1.size()+nums2.size())/2 );
        std::unordered_set<int> set(nums1.begin(),nums1.end());
        for(int i:nums2){
            if(set.count(i) !=0){
                out.push_back(i);
                set.erase(i);
            }
        }
        return out;
    }
};




std::ostream& operator << (std::ostream& os,vector<int> out){
    if(out.size()==0){return os;}
    os << "[";
    for(int i=0;i<out.size();++i){
        os << out[i];
        if(i!= out.size()-1){
            os <<",";
        }
    }
    os << "]";
    return os;
}

int main(){
    Solution sol;
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};

    std::cout << sol.intersection(nums1,nums2);
    return 0;
}