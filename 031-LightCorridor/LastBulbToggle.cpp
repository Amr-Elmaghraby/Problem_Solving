#include <iostream>  // For input/output operations
#include <cmath>     // For using the sqrt function
using namespace std;

int main(){
    // Declare an unsigned integer 'n' and initialize it to 1 (input will overwrite it)
    unsigned int n = 1;

    // Continue the loop until input is not zero
    while(cin >> n && n != 0){  // Read input and check if it's not zero
        // Calculate the integer part of the square root of 'n'
        unsigned int sq = sqrt(n);
        
        // If 'sq * sq' equals 'n', it means 'n' is a perfect square
        if(sq * sq == n){
            cout << "yes" << endl;  // Output "yes" if n is a perfect square
        } else {
            cout << "no" << endl;   // Output "no" if n is not a perfect square
        }
    }

    // Return 0 to indicate the program finished successfully
    return 0;
}
