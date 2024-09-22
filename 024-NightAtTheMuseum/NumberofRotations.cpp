#include <iostream>
#include <cmath> // For abs() function
using namespace std;

int main() {
    string s;
    cin >> s;
    int Num_Rot = 0;
    char prev = 'a'; // Starting at 'a'

    for (char c : s) {
        // Calculate the direct distance between current and previous characters
        int tmp = abs(c - prev);
        
        // Choose the minimal rotation direction
        if (tmp > 13) {
            // If clockwise distance is greater than 13, go counter-clockwise
            Num_Rot += 26 - tmp;
        } else {
            // Otherwise, go clockwise
            Num_Rot += tmp;
        }
        
        // Update the previous character to the current one
        prev = c;
    }

    cout << Num_Rot << endl; // Output the total minimum rotations required

    return 0;
}
