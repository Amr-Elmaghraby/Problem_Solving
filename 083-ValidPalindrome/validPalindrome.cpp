#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        if(s.size()==0){return true;}
        int left = 0;
        int right = s.size() - 1;
        while(left <= right)
        {
            while(left<right&&(s[left] < 'a' || s[left] > 'z') && (s[left]<'0'||s[left]>'9') )
            {
                if(s[left]>='A'&&s[left]<='Z'){
                    s[left] +=32; 
                }
                else{++left;}
            }
            while(left<right&&(s[right] < 'a' || s[right] > 'z') && (s[right]<'0'||s[right]>'9'))
            {
                if(s[right]>='A'&&s[right]<='Z'){
                    s[right] +=32; 
                }
                else{--right;}
            }

            if (s[left] != s[right])
            {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

int main()
{
    string s = "A man, a plan, a canal: Panama";
    // string s = " ";
    Solution sol;
    std::cout << sol.isPalindrome(s);
    return 0;
}