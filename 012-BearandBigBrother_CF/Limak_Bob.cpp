#include <iostream>

using namespace std;

int main() {
    int Limak_w, Bob_w;
    cin >> Limak_w >> Bob_w;  // Combined input for Limak's and Bob's weights

    int years = 0;

    // While Limak's weight is less than or equal to Bob's, Limak's weight triples and Bob's weight doubles
    while (Limak_w <= Bob_w) {
        Limak_w *= 3;
        Bob_w *= 2;
        years++;  // Increment the year count
    }

    // Output the number of years needed for Limak to surpass Bob
    cout << years << endl;

    return 0;
}
