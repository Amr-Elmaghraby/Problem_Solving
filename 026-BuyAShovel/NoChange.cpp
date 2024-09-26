#include <iostream>
using namespace std;

int main() {
    int Shovel_Price = 0, r_Burles = 0;
    cin >> Shovel_Price >> r_Burles; // Input the price of one shovel and the extra coin value (r Burles)

    int Num_of_Shovels = 1; // Start with buying at least one shovel

    // Loop to find the minimum number of shovels Polycarp needs to buy
    while (Num_of_Shovels <= 9) {
        // Calculate the total cost for the current number of shovels
        int total_cost = Num_of_Shovels * Shovel_Price;

        // Calculate the last digit of the total cost
        int last_digit = total_cost % 10;

        // Check if the last digit of the total cost is 0 (no change needed) 
        // or equal to r_Burles (Polycarp can use his extra coin)
        if (last_digit == 0 || last_digit == r_Burles) {
            break; // If either condition is true, exit the loop
        }

        Num_of_Shovels++; // Increment the number of shovels and try again
    }

    // Output the minimum number of shovels needed to pay without requiring change
    cout << Num_of_Shovels << endl;
}
