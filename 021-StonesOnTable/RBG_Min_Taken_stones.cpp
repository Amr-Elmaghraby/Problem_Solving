#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n; // Read the length of the string
    string s;
    cin >> s; // Read the string
    
    int prev = s[0]; // Initialize prev with the first character of the string
    int Min_to_Remove = 0; // Initialize the count of minimum removals to 0
    
    // Iterate through the string starting from the second character
    for (int i = 1; i < n; ++i) {
        if (s[i] == prev) {
            Min_to_Remove++; // Increment the removal count if current char is the same as prev
        }
        prev = s[i]; // Update prev to the current character
    }
    
    cout << Min_to_Remove << endl; // Output the result
}
