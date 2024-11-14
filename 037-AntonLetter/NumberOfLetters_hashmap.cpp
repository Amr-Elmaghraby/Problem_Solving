#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<char> hash;
    hash.reserve(26);
    char ch = 0;
    do
    {
        std::cin >> ch;
        if (ch >= 'a' && ch <= 'z')
        {
            if (hash.find(ch) == hash.end())
            {
                hash.insert(ch);
            }
        }
    } while (ch != '}');

    std::cout << hash.size();

    return 0;
}