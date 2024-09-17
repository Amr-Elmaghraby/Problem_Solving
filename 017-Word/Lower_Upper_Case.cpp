#include<iostream>
using namespace std;

// Function to convert a string to either lowercase or uppercase
// based on the value of 'lower_sign'
void LowerOrUpper(string* s, int s_size, bool lower_sign) {

    // Loop through each character in the string
    for (int i = 0; i < s_size; ++i) {
        // Check if the character needs to be converted:
        // 'cas' will be true (1) if the character needs to change, false (0) otherwise.
        // 1. lower_sign is true (we want to lowercase), OR
        // 2. the character is already lowercase (ASCII > 96),
        // 3. AND we are not trying to lowercase an already lowercase letter.
        int cas = (lower_sign || (int)(*s)[i] > 96) && !(lower_sign && (int)(*s)[i] > 96);

        // Adjust the character by either adding or subtracting 32 (the difference between
        // uppercase and lowercase letters in ASCII):
        // If lower_sign is true (convert to lowercase), multiply by 1.
        // If lower_sign is false (convert to uppercase), multiply by -1.
        (*s)[i] += cas * (lower_sign * 2 - 1) * 32;
    }
}

int main() {
    string s; 
    cin >> s; // Input the string from the user

    int lowercase = 0; // Counter for the number of lowercase letters in the string

    // Count how many characters in the string are lowercase
    for (int i = 0; i < s.size(); ++i) {
        if ((int)s[i] > 90) {  // ASCII value > 90 means it's lowercase (a-z)
            lowercase++;
        }
    }

    // Determine half the size of the string
    int half_size = s.size() / 2;
    
    // If the string length is odd, round half_size up by adding 1
    if (s.size() % 2) {
        half_size++;
    }

    // If the number of lowercase letters is greater than or equal to half the string,
    // convert the whole string to lowercase. Otherwise, convert to uppercase.
    if (lowercase >= half_size) {
        LowerOrUpper(&s, s.size(), true);  // Convert to lowercase
    } else {
        LowerOrUpper(&s, s.size(), false); // Convert to uppercase
    }

    // Output the modified string
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}
