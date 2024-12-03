#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> perm;
        stack<pair<vector<int>,int>> st;
        // Push an empty permutation with index 0
        st.push({{},0});

        while(!st.empty())
        {
            auto[current_perm,index] = st.top();
            st.pop();

            if(index == nums.size())
            {
                // Completed permutation
                perm.push_back(current_perm);
            }else{
                for(int i=0;i<=current_perm.size();++i)
                {
                    vector<int> new_perm = current_perm;
                    new_perm.insert(new_perm.begin()+i,nums[index]);
                    st.push({new_perm,index+1});
                }
            }
        }
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
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};

    Solution sol;
    vector<vector<int>> res = sol.permute(nums);

    std::cout << res;

    return 0;
}