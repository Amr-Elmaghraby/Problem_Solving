#include<iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    int removeDuplicates(vector<int>& nums){
        int j=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i] != nums[i-1]){
                nums[j] = nums[i];
                j++;
            }
        }
        for(int n:nums){
            cout << n<<',';
        }
        cout <<endl;
        return j;
    }
};



int main(){
    Solution sol;
    vector<int> vc = {1,1,2};
    int out = sol.removeDuplicates(vc);

    cout << out <<endl;
}