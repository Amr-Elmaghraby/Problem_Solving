#include <iostream>

int main()
{
    int Tot_of_cakes = 0, time_needed_of_oven = 0, Number_of_cakes_per_time = 0, second_oven_build = 0;

    // Read the input values
    std::cin >> Tot_of_cakes >> time_needed_of_oven >> Number_of_cakes_per_time >> second_oven_build;

    // Time to bake all cakes using the first oven only
    int time_with_first_oven = ((Tot_of_cakes + Number_of_cakes_per_time - 1) / Number_of_cakes_per_time) * time_needed_of_oven;

    // If the first oven alone can finish the job before the second oven is built
    if (time_with_first_oven <= second_oven_build) {
        std::cout << "NO" << std::endl;
    } else {
        // How many cakes we need to bake after the second oven is built
        int cakes_baked_by_first_oven = (second_oven_build / time_needed_of_oven) * Number_of_cakes_per_time;
        int remaining_cakes = Tot_of_cakes - cakes_baked_by_first_oven;

        // Both ovens bake 8 cakes per 6 minutes after the second oven is built
        //! Time Will not be correct in all cases :( ex. "9,6,4,5"
        int time_with_both_ovens = second_oven_build + ((remaining_cakes + 7) / 8) * time_needed_of_oven;

        // If using both ovens results in faster baking, print "YES"
        if (time_with_both_ovens < time_with_first_oven) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
