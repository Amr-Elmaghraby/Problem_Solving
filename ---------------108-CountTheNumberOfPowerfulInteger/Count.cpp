#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

struct input
{
    long long start;
    long long finish;
    int limit;
    string s;
    // input():start(1),finish(6000),limit(4),s("124"){}
    // input():start(15),finish(215),limit(6),s("10"){}
    // input():start(1),finish(971),limit(9),s("17"){}
    input() : start(15398), finish(1424153842), limit(8), s("281") {}
};

class Solution
{
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s)
    {
        long long count = 0;

        // Check if all digits in s are <=limit
        for (char c : s)
        {
            if (c - '0' > limit)
            {
                return 0;
            }
        }

        long long s_num = stoll(s);
        int s_size = s.size();

        // Digit DP function to count numbers <= P with all digits <= limit
        //     auto count_numbers_up_to = [](long long p,int limit)->long long{
        //         string s_p  = to_string(p);
        //         int n= s_p.size();
        //         long long dp[16][2][2];
        //         memset(dp,-1,sizeof(dp));

        // }
        return count;
    }
};

std::ostream &operator<<(std::ostream &os, input str)
{
    os << str.start;
    os << std::endl;
    os << str.finish;
    os << std::endl;
    os << str.limit;
    os << std::endl;
    os << str.s;
    os << std::endl;
    return os;
}

int main()
{
    Solution sol;
    input input1;
    long long out = sol.numberOfPowerfulInt(input1.start, input1.finish, input1.limit, input1.s);
    std::cout << input1;
    std::cout << out;
    return 0;
}