#include <iostream>
#include <string>

class Solution
{
public:
    std::string mergeAlternately(std::string word1, std::string word2)
    {
        std::string merged;
        size_t i = 0;
        while ((i < word1.size()) || (i < word2.size()))
        {
            if (i < word1.size())
            {
                merged += word1[i];
            }
            if (i < word2.size())
            {
                merged += word2[i];
            }
            ++i;
        }
        return merged;
    }
};

int main()
{
    std::string word1 = "abcd";
    std::string word2 = "pq";

    Solution sol;
    std::string res = sol.mergeAlternately(word1, word2);
    std::cout << res;

    return 0;
}