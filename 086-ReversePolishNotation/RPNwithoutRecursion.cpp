#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
    public:
    int evalRPN(vector<string> &tokens)
    {
        std::stack<int> stk;

        for(string &token:tokens)
        {
            if(token == "+"||token == "-"||token == "*"||token == "/")
            {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if(token == "+")
                    stk.push(a+b);
                else if(token == "-")
                    stk.push(a-b);
                else if(token == "*")
                    stk.push(a*b);
                else if(token == "/")
                    stk.push(a/b);
            }else{
                stk.push(std::stoi(token));
            }
        }
        return stk.top();
    }
};

int main()
{
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution sol;
    std::cout << sol.evalRPN(tokens);
    return 0;
}