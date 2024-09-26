#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to multiply two large numbers represented as strings
string MultiplyLargeNumbers(string num1, string num2) {
    // If one of the numbers is "0", return "0"
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    
    // Initialize the result string with size num1.size() + num2.size()
    string res(num1.size() + num2.size(), '0');
    
    // Reverse the input strings for easier processing from least significant to most
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    // Perform the multiplication digit by digit
    for (int i = 0; i < num1.size(); ++i) {
        for (int j = 0; j < num2.size(); ++j) {
            int currentPos = i + j;
            // Add to the result at the current position
            int tmp = (num1[i] - '0') * (num2[j] - '0') + (res[currentPos] - '0');            
            res[currentPos] = (tmp % 10) + '0';   // Store the remainder in the current position
            res[currentPos + 1] += (tmp / 10);    // Carry to the next position
        }
    }
    
    // Remove all unnecessary leading zeros
    while (res.back() == '0') {
        res.pop_back();
    }

    // Reverse the result back to its correct order
    reverse(res.begin(), res.end());
    
    return res;
}

int main() {
    string X, Y;
    // Take input and multiply until the end of input
    while (cin >> X >> Y) {
        // Call MultiplyLargeNumbers and print the result
        cout << MultiplyLargeNumbers(X, Y) << endl;
    }
    return 0;
}
