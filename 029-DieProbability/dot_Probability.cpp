#include <iostream>
#include <algorithm>
using namespace std;

// Function to calculate the Greatest Common Divisor (GCD) using the Euclidean algorithm
int GCD(int Param_a, int Param_b) {
    // If Param_b is zero, return Param_a (base case of recursion)
    return Param_b == 0 ? Param_a : GCD(Param_b, Param_a % Param_b);
}

int main() {
    int Y_W[2] = {0}; // Array to store the scores of Yakko and Wakko
    cin >> Y_W[0] >> Y_W[1]; // Input the scores of Yakko and Wakko

    // Calculate the number of winning outcomes for Dot
    // The winning outcomes are from the maximum score to 6, hence (6 - max + 1)
    int prob = 6 - max(Y_W[0], Y_W[1]) + 1;

    // Calculate the GCD of the winning outcomes and the total possible outcomes (6)
    int Greatest_Common_Divisor = GCD(prob, 6);

    // Output the probability in the form of an irreducible fraction
    cout << prob / Greatest_Common_Divisor << '/' << 6 / Greatest_Common_Divisor << endl;

    return 0; // Return 0 to indicate successful execution
}
