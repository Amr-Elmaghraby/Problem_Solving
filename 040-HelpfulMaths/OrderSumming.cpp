#include <iostream>
#include <string>

int main()
{
    int nums[3] = {0};
    std::string st;
    std::cin >> st;
    for (int i = 0; i < st.size(); i += 2)
    {
        int tmp = st[i] - '1';
        nums[tmp]++;
    }
    for (int i = 0; i < 3; ++i)
    {
        while (nums[i])
        {
            std::cout << i+1;
            --nums[i];
            if(nums[0] ==0 && nums[1] ==0 && nums[2]==0) break;
            std::cout << '+';
        }
    }
    std::cout << std::endl;
    return 0;
}