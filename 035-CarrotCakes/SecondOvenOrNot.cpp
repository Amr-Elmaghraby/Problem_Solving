#include <iostream>
#include <algorithm>

int main()
{
    // Declare variables to hold input values
    int Tot_of_cakes = 0, time_needed_of_oven = 0, Number_of_cakes_per_time = 0, second_oven_build = 0;

    // Read input values from the user
    std::cin >> Tot_of_cakes >> time_needed_of_oven >> Number_of_cakes_per_time >> second_oven_build;

    // Calculate the total time needed to bake all cakes using only the first oven
    // (Number of full batches required to bake all cakes) * (time per batch)
    int time_with_first_oven = ((Tot_of_cakes + Number_of_cakes_per_time - 1) / Number_of_cakes_per_time) * time_needed_of_oven;

    // Check if the first oven alone finishes baking before or at the time the second oven is built
    if (time_with_first_oven <= second_oven_build)
    {
        // If the first oven alone can finish before the second oven is ready, print "NO"
        std::cout << "NO" << std::endl;
    }
    else
    {
        // Calculate the impact of using the second oven
        // The second oven will start after 'second_oven_build' time, and we assume another batch cycle after that
        int second_oven_impact = time_needed_of_oven + second_oven_build;

        // Compare the time with both ovens (second_oven_impact) with the time using only the first oven
        if (second_oven_impact < time_with_first_oven)
        {
            // If using both ovens finishes faster, print "YES"
            std::cout << "YES" << std::endl;
        }
        else
        {
            // If the second oven doesn't help, print "NO"
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
