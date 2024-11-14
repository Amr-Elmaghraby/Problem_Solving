#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    int childs[n];
    int count[3] = {0};
    for (int i = 0; i < n; ++i)
    {
        std::cin >> childs[i];
        ++count[childs[i] - 1];
    }

    int numberOfTeams = *std::min_element(count, count + (sizeof(count) / sizeof(count[0])));
    std::cout << numberOfTeams << std::endl;
    for (int tr = 0; tr < numberOfTeams; ++tr)
    {
        int i=1;
        backToNextNum:
        for (int j = 0; j < n; ++j)
        {
            if (childs[j] == i)
            {
                std::cout << j + 1 << ' ';
                childs[j] = 0;
                ++i;
                goto backToNextNum;//0o or just make j = -1
            }
        }
        std::cout << std::endl;
    }

    return 0;
}