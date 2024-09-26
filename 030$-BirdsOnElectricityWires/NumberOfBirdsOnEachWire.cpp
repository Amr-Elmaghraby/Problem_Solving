#include<iostream>
using namespace std;

int main() {
    // Variable to store the number of wires
    int Wires = 0;
    cin >> Wires; // Input the number of wires

    // Array to store the number of birds on each wire
    int BirdsOnWire[Wires] = {0}; 
    for (int i = 0; i < Wires; ++i) {
        cin >> BirdsOnWire[i]; // Input the initial number of birds on each wire
    }

    // Variable to store the number of shots
    int NumberOfShots = 0;
    cin >> NumberOfShots; // Input the number of shots

    // Loop through each shot
    for (int i = 0; i < NumberOfShots; ++i) {
        int x, y; // x is the wire number, y is the position of the bird shot
        cin >> x >> y; // Input the shot information
        x -= 1; // Adjust for 0-based indexing
        
        // Calculate the number of birds on the left and right of the shot bird
        int left = y - 1; // Birds to the left of the shot bird
        int right = BirdsOnWire[x] - y; // Birds to the right of the shot bird
        
        // Set the current wire to 0 since all birds will jump off
        BirdsOnWire[x] = 0; 
        
        // Move the left birds to the upper wire (if it exists)
        if (x >= 1) { // Check if there is a wire above
            BirdsOnWire[x - 1] += left; // Add left birds to the wire above
        }
        
        // Move the right birds to the lower wire (if it exists)
        if (x + 1 < Wires) { // Check if there is a wire below
            BirdsOnWire[x + 1] += right; // Add right birds to the wire below
        }
    }

    // Output the final number of birds on each wire
    for (int i = 0; i < Wires; ++i) {
        cout << BirdsOnWire[i] << endl; // Print the count of birds remaining on each wire
    }

    return 0; //* End of the program
}
