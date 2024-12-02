#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    std::vector<vector<std::string>> groupAnagrams(vector<string> &strs)
    {
        // vector of vectors to store anagrams
        vector<vector<std::string>> anagramsGroup;
        // UnorderedMap to store sorted word as a key and pushing strings with similar key together
        // NOTE: here having same key only means the strings are anagrams of each others
        // NOTE: using vector<string> is a very good solution here to make map save multi
        // values to the same key which :)))
        std::unordered_map<string, vector<string>> anagramMap;

        for (string str : strs)
        {
            std::string sortedWord = str;
            //Sort sortedWord using sort function
            std::sort(sortedWord.begin(), sortedWord.end());
            anagramMap[sortedWord].push_back(str);
        }

        // for each vector of strings gets created in each key save it in vector of vector anagramsgroup
        for (std::unordered_map<string, vector<string>>::iterator it = anagramMap.begin();
             it != anagramMap.end(); ++it)
        {
            anagramsGroup.push_back(it->second);
        }

        return anagramsGroup;
    }
};

std::ostream &operator<<(std::ostream &os, vector<vector<string>> str)
{
    os << "[";
    for (int i = 0; i < str.size(); ++i)
    {
        os << "[";
        for (int j = 0; j < str[i].size(); ++j)
        {
            os << "\"";
            os << str[i][j];
            os << "\"";
            if (j != str[i].size() - 1)
                os << ",";
        }
        os << "]";
        if (i != str.size() - 1)
            os << ",";
    }
    os << "]";
    return os;
}

int main()
{
    vector<string> str = {{"hhhhu"}, {"tttti"}, {"tttit"}, {"hhhuh"}, {"hhuhh"}, {"tittt"}, {"duh"}, {"ill"}, {"aye"}, {"old"}};
    Solution sol;
    vector<vector<string>> res = sol.groupAnagrams(str);
    std::cout << res;
    return 0;
}