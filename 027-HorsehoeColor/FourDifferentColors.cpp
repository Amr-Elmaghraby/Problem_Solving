#include <iostream>
using namespace std;

int main() {
    int Colors[4] = {0}; // Array to store the colors of the horseshoes
    int Num_Unique_Color = 0; // Counter for the number of unique colors

    // Input the colors of the horseshoes
    for (int i = 0; i < sizeof(Colors) / sizeof(Colors[0]); ++i) {
        cin >> Colors[i]; // Read each color
    }

    // Loop through each color to check for uniqueness
    for (int i = 0; i < 4; ++i) {
        bool unique = true; // Assume the current color is unique
        // Compare the current color with all subsequent colors
        for (int j = i + 1; j < 4; ++j) {
            if (Colors[i] == Colors[j]) { // Check if there's a duplicate
                unique = false; // Mark as not unique if found
                break; // Exit the inner loop early
            }
        }
        // If the color is unique, increment the unique color counter
        if (unique) {
            Num_Unique_Color++;
        }
    }

    // Output the number of horseshoes Valera needs to buy
    cout << (4 - Num_Unique_Color) << endl; // Calculate and print the difference
    return 0; // End of the program
}
