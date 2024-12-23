#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
using namespace std;

class Solution
{
public:
    int Recursive(std::stack<string> &st)
    {
        if (st.top() != "+" && st.top() != "-" && st.top() != "/" && st.top() != "*")
        {
            int tmp_parm = std::stoi(st.top());
            st.pop();
            return tmp_parm;
        }

        char c = st.top()[0];
        st.pop();
        int parm2 = Recursive(st);
        int parm1 = Recursive(st);
        switch (c)
        {
        case '+':
            return parm1 + parm2;
        case '-':
            return parm1 - parm2;
        case '*':
            return parm1 * parm2;
        case '/':
            return parm1 / parm2;
        }
        // should never reach here
        return 0;
    }
    int evalRPN(vector<string> &tokens)
    {
        int res = 0;
        std::stack<string> st;
        for (string &str : tokens)
        {
            st.push(str);
        }

        res = Recursive(st);

        return res;
    }
};

int main()
{
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution sol;
    std::cout << sol.evalRPN(tokens);
    return 0;
}