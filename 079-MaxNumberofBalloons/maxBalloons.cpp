#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        // Start with determine max possible "balloon" word that could be in text string
        int maxPossible = text.size() / 7;
        // If text.size() is smaller than 7 "balloon word size" so it couldn't store any balloon word
        //      so return 0
        if (maxPossible == 0)
        {
            return 0;
        }

        // hashmap to store max expected numbers of each character in balloon word
        // as considering text is consists of only balloon words 
        std::unordered_map<char, int> mp={{'b',maxPossible},{'a',maxPossible},{'l',2*maxPossible}
        ,{'o',2*maxPossible},{'n',maxPossible}};

        // Iterator through text
        for (char c : text)
        {
            // if character is indeed in map then decrease freq of it by 1 
            if (mp.count(c))
            {
                --mp[c];
                // if character freq hit 0 then just remove it from map
                if (mp[c] == 0)
                {
                    mp.erase(c);
                }
            }
        }
        // after removing all characters of text that could for real create balloon word
        // now we should adjust remaining freq of characters that earlier thought to be a correct balloon word
        int countedWrong = 0;
        // iterate through remaining characters in hashmap
        // as of remaining frequences of hashmap, the max freq of it can be considered
        //      to be correct countedWrong words. 
        for (std::unordered_map<char, int>::iterator it = mp.begin(); it != mp.end(); ++it)
        {
            // store freq remaining of current character as current_max
            int current_max = it->second;
            // right adjust to 'l' and 'o' characters as both normal freq is 2 in one balloon word
            if (it->first == 'l' || it->first == 'o')
            {
                // adjust current_mx correctly as if is odd value not to ignore 1 wrong feq value
                if(current_max%2){++current_max;}
                current_max /= 2;
            }
            // correct countedWrong to be current_mx if to be bigger than countedWrong
            countedWrong = current_max > countedWrong ? current_max : countedWrong;
        }
        // return maxPossible mins countedwrong 
        return (maxPossible - countedWrong);
    }
};

int main()
{
    // string str = "loonbalxballpoon";
    string str = "krhizmmgmcrecekgyljqkldocicziihtgpqwbticmvuyznragqoyrukzopfmjhjjxemsxmrsxuqmnkrzhgvtgdgtykhcglurvppvcwhrhrjoislonvvglhdciilduvuiebmffaagxerjeewmtcwmhmtwlxtvlbocczlrppmpjbpnifqtlninyzjtmazxdbzwxthpvrfulvrspycqcghuopjirzoeuqhetnbrcdakilzmklxwudxxhwilasbjjhhfgghogqoofsufysmcqeilaivtmfziumjloewbkjvaahsaaggteppqyuoylgpbdwqubaalfwcqrjeycjbbpifjbpigjdnnswocusuprydgrtxuaojeriigwumlovafxnpibjopjfqzrwemoinmptxddgcszmfprdrichjeqcvikynzigleaajcysusqasqadjemgnyvmzmbcfrttrzonwafrnedglhpudovigwvpimttiketopkvqw";
    Solution sol;
    std::cout << sol.maxNumberOfBalloons(str);
    return 0;
}