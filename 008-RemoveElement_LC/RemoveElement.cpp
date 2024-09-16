#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
      int removeElement(vector<int>& nums, int val) {
        int j=0;
        for(int i =0 ; i< nums.size();++i){
            if(nums[i] != val){
                nums[j] = nums[i];
                j++;
           }
        }
        return j;
    }
};

int main(){
    Solution sol;
    vector<int> vc = {0,1,2,2,3,0,4,2};
    int val=2;
    int out = sol.removeElement(vc,val);
    for(int n : vc){
        cout << n << " , " ;
    }
    cout << endl<<out << endl;
}