#include <iostream>
using namespace std;

int main() {
    string s, c; // Declare strings to hold the colors of stones and instructions
    cin >> s >> c; // Read input for the sequence of stones (s) and the instructions (c)

    int liss_pos = 0; // Initialize Liss's position on the stones (0-based indexing)

    // Iterate over each character in the instruction string c
    for (char ch : c) {
        // Check if the current instruction matches the color of the stone Liss is on
        if (ch == s[liss_pos]) {
            liss_pos++; // Move Liss to the next stone
            // Check if Liss has moved beyond the last stone
            if (liss_pos >= s.length()) {
                break; // Stop processing if we've reached the end of the stones
            }
        }
    }

    // Output the final position of Liss, converting from 0-based to 1-based indexing
    cout << liss_pos + 1 << endl;

    return 0; // End of the program
}
