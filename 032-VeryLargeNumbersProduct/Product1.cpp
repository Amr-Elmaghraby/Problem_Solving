#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


string trimLeadingZeros(string num) {
    int i = 0;
    // Find the first non-zero character
    while (i < num.size() && num[i] == '0') {
        ++i;
    }
    // Return the substring starting from the first non-zero character
    return (i == num.size()) ? "0" : num.substr(i);
}

// Function to multiply two large numbers represented as strings
string MultiplyLargeNumbers(string num1, string num2) {
    // If one of the numbers is "0", return "0" since the product will be zero
    if (num1 == "0" || num2 == "0") {
        return "0";
    }

    // Initialize an empty string to store the result
    string res = "";

    // Reverse both strings to process the least significant digits first
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    // Loop through each digit of the first number
    for(int i = 0; i < num1.size(); ++i) {
        // Loop through each digit of the second number
        for(int j = 0; j < num2.size(); ++j) {
            // Multiply the digits from num1 and num2 and store in tmp
            int tmp = (num1[i] - '0') * (num2[j] - '0');
            int itr = 0; // Iterator for handling carry-over if needed

            // Continue the loop as long as tmp has a non-zero value
            do {
                // Check if the current position in the result already has a value
                if(res.size() > (i + j + itr)) {
                    // Add tmp to the existing value in res and store the updated value
                    tmp += res[i + j + itr] - '0'; // Convert from char to int
                    res[i + j + itr] = tmp % 10 + '0'; // Update with the remainder
                } else {
                    // If the result size is not large enough, insert a new digit
                    res.insert(i + j + itr, 1, (tmp % 10 + '0')); // Insert at correct position
                }
                tmp /= 10; // Move to the next digit (carry-over)
                ++itr; // Increment the iterator to handle carry-over digits
            } while(tmp); // Repeat if there's still a carry-over left
        }
    }

    // Remove any trailing zeros from the result after all calculations are done
    while(res.back() == '0') {
        res.pop_back();
    }

    // Reverse the result back to the correct order (since it was processed in reverse)
    reverse(res.begin(), res.end());

    // Return the final result
    return res;
}

int main() {
    // Strings to store the input numbers
    string X, Y;

    // Read input numbers X and Y in a loop and calculate their product
    while(cin >> X >> Y) {
        X = trimLeadingZeros(X);
        Y = trimLeadingZeros(Y);
        // Call MultiplyLargeNumbers to get the result and print it
        cout << MultiplyLargeNumbers(X, Y) << endl;
    }

    return 0; // End of the program
}
