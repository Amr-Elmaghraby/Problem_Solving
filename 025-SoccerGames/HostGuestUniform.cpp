#include <iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace to avoid prefixing std:: with every usage

int main() {
    int Num_of_Teams = 0; // Variable to store the number of teams participating
    int HostGuestUniform = 0; // Counter to store the number of matching home and guest uniforms

    // Read the number of teams from the input
    cin >> Num_of_Teams;

    // Arrays to store home and guest uniform colors for each team
    int Teams_Home_Uniform[Num_of_Teams];
    int Teams_Guest_Uniform[Num_of_Teams];

    // Read home and guest uniform colors for each team
    for (int i = 0; i < Num_of_Teams; ++i) {
        // Input format: guest uniform first, then home uniform
        cin >> Teams_Guest_Uniform[i] >> Teams_Home_Uniform[i];
    }

    // Compare each team's home uniform with every other team's guest uniform
    for (int i = 0; i < Num_of_Teams; ++i) {
        for (int j = 0; j < Num_of_Teams; ++j) {
            // The check if `i == j` ensures that a team is not compared with itself.
            // This check is not necessary as teams' home and guest uniforms are always compared separately.
            if (i == j) { continue; } // Can be removed as comparing a team with itself doesn't cause an issue
            
            // If the home uniform of team `i` matches the guest uniform of team `j`, increment the counter
            if (Teams_Home_Uniform[i] == Teams_Guest_Uniform[j]) {
                HostGuestUniform++;
            }
        }
    }

    // Output the total number of matches where the home uniform of one team matches the guest uniform of another team
    cout << HostGuestUniform << endl;

    return 0; // Return 0 to indicate successful execution
}
