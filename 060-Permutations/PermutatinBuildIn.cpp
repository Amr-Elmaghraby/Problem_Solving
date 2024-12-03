#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{
    public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> perm;
                
        do{
            perm.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));

        return perm;
    }
};


std::ostream& operator << (std::ostream& os ,vector<vector<int>> vec)
{
    os <<"[";
    for(int i=0;i<vec.size();++i)
    {
        os<<"[";
        for(int j=0;j<vec[i].size();++j)
        {
            os<< vec[i][j];
            if(j != vec[i].size()-1 )
            {
                os<<",";
            }
        }
        os<<"]";
        if(i != vec.size()-1 )
        {
            os<<",";
        }
    }
    os<<"]"<<std::endl;
    return os;
}


int main()
{
    vector<int> nums = {1,2,3,4};
    Solution sol;
    vector<vector<int>> res;
    res = sol.permute(nums);

    std::cout << res;


    return 0;
}