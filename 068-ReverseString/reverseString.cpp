#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution
{
    public:
    void reverseString(vector<char> &s)
    {
        int end=s.size()-1;
        for(int i=0;i<(s.size()/2);++i)
        {
            char tmp = s[i];
            s[i] = s[end];
            s[end--] = tmp;
        }
    }
};

std::ostream& operator<< (std::ostream& os,vector<char>& ch)
{
    for(char c:ch)
    {
        os<<c;
    }
    return os;
}

int main()
{
    vector<char> str={'A','m','r',' ','E','l','m','a','g','h','r','a','b','y'};

    Solution sol;
    sol.reverseString(str);

    std::cout << str;

}