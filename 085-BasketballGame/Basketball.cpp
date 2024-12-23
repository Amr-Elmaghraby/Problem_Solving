#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        std::stack<int> st;
        int res = 0;
        for (int i = 0; i < operations.size(); ++i)
        {
            char c = operations[i][0];
            if (c == 'D')
                st.push(st.top() * 2);
            else if (c == 'C')
                st.pop();
            else if (c == '+')
            {
                int top = st.top();
                st.pop();
                int top2 = st.top();
                st.push(top);
                st.push(top + top2);
            }
            else
            {
                int tmp = std::stoi(operations[i]);
                st.push(tmp);
            }
        }
        while (st.size())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main()
{
    std::vector<std::string> str = {"1","C","-62","-45","-68"};
    Solution sol;
    std::cout << sol.calPoints(str);
    return 0;
}