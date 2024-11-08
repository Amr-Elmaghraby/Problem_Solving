#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int partition(vector<int> &nums, int low, int high)
{
    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
    {
        if (nums[j] <= pivot)
        {
            ++i;
            std::swap(nums[i], nums[j]);
        }
    }
    std::swap(nums[i + 1], nums[high]);
    return i + 1;
}

void quickSort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int pi = partition(nums, low, high);

        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high);
    }
}

class Solution
{
public:
    bool conatinsDuplicate(vector<int> &nums)
    {
        if (!nums.size())
            return false;
        quickSort(nums, 0, nums.size() - 1);
        int prev = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (prev == nums[i])
            {
                return true;
            }
            else
            {
                prev = nums[i];
            }
        }
        return false;
    }
};

std::ostream &operator<<(std::ostream &os, vector<int> &vc)
{
    if (!vc.size())
        return os;
    os << '[';
    for (int i = 0; i < vc.size(); ++i)
    {
        os << vc[i];
        if (i < vc.size() - 1)
            os << ',';
    }
    os << ']';
    return os;
}

int main()
{
    std::vector<int> x;
    Solution sol;
    x.reserve(10);
    while (1)
    {
        int tmp;
        std::cin >> tmp;
        // 0o check if std::cin didn't fail "Invalid input 'character rather than number' "
        if (std::cin.fail())
        {
            std::cin.clear(); // clear failbit
            char ch;
            std::cin >> ch; // read failed as an character value
            if (ch == ']')
            {
                break;
            }
            // Ignore any remaining characters until the next newline
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        x.push_back(tmp);
    }

    bool res = sol.conatinsDuplicate(x);

    std::cout << x << std::endl;
    std::cout << res;
    return 0;
}