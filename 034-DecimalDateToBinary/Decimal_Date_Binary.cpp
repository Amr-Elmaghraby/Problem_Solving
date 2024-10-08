#include <iostream>
#include <algorithm> // For std::reverse
#include <cmath>     // For pow

using namespace std;

class Solution
{
public:
    // Function to convert a date string to its binary representation
    string convertDateToBinary(string date)
    {
        string s = "";       // Initialize an empty string to hold the binary result
        s.reserve(10);       // Reserve space for the expected size of the output
        int tmp = 0;         // Temporary variable to build each part of the date
        int unit = 0;        // To keep track of the position in the current number (unit)

        // Iterate through the date string from the end to the beginning
        for (int i = date.size() - 1; i >= -1; --i) {
            //0r When we reach the start of the string or encounter a dash ('-')
            //0r As a result of short-circuiting, date[-1] will not be evaluated.
            //0o If, in other cases, you want both to be evaluated, you can use bitwise OR " | ".
            if (i == -1 || date[i] == '-') {
                unit = 0;  // Reset unit for the next number
                // Convert the current number (tmp) to binary
                while (tmp) {
                    // Append '1' or '0' to the result string based on the binary value
                    tmp % 2 ? s += '1' : s += '0'; // Update result string with binary digits
                    tmp /= 2; // Divide by 2 to shift right
                }
                s += '-'; // Append a dash after each part
            }
            else
            {
                // Construct the current number by adding digits
                tmp += (date[i] - '0') * pow(10, unit); // Convert char to int and position it
                unit++; // Increment the unit position
            }
        }
        s.pop_back(); // Remove the last dash added after the final number
        reverse(s.begin(), s.end()); // Reverse the string to get the correct order
        return s; // Return the resulting binary string
    }
};

int main()
{
    Solution s; // Create an instance of the Solution class
    string in; // Declare input string
    cin >> in; // Read input date in the format YYYY-MM-DD
    string out = s.convertDateToBinary(in); // Convert to binary format

    cout << out << endl; // Output the binary representation
    return 0; // Exit the program
}
