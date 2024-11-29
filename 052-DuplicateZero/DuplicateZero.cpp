#include <iostream>
#include <vector>

class Solution
{
public:
    void duplicateZeros(std::vector<int> &arr)
    {
        // Count Zeros
        int zeros = 0;
        int n = arr.size();
        for (size_t i = 0; i < n; ++i)
        {
            if (!arr[i])
            {
                ++zeros;
            }
        }

        // Second pass: Traverse the array backward to duplicate zeros
        int itr = n - 1;
        while (zeros)
        {
            // Check if the current element should be copied within bounds
            if ((itr + zeros) < n)
            {
                arr[itr + zeros] = arr[itr]; // Copy the current element to its new position
            }
            // If the current element is zero, handle duplication
            if (arr[itr] == 0)
            {
                --zeros; // Decrement zeros counter as this zero is now processed
                if ((itr + zeros) < n)
                {
                    arr[itr + zeros] = 0; // Duplicate the zero if within bounds
                }
            }
            --itr; // Move to the previous element
        }
    }
};

std::ostream &operator<<(std::ostream &os, const std::vector<int> &arr)
{
    os << '[';
    for (size_t i = 0; i < arr.size() - 1; ++i)
    {
        os << arr[i] << ", ";
    }
    os << arr[arr.size() - 1] << ']' << std::endl;

    return os;
}

int main()
{

    // std::vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    std::vector<int> arr = {0,1,7,6,0,2,0,7};
    Solution sol;
    sol.duplicateZeros(arr);

    std::cout << arr;

    return 0;
}