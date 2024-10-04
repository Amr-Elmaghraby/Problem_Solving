#include <iostream>

int main()
{
    // Declare variables for the number of oranges, the maximum size that can be juiced, and the waste section size.
    unsigned int NumberOfOranges, MaxSize, WasteSize;
    
    // Read the values of NumberOfOranges, MaxSize (b), and WasteSize (d) from input.
    std::cin >> NumberOfOranges >> MaxSize >> WasteSize;
    
    // Initialize a counter for the number of times the juicer is emptied.
    unsigned int Empty = 0;
    
    // Initialize a variable to accumulate the total size of oranges squeezed into the juicer.
    unsigned int SumOfOranges = 0;

    // Loop through each orange.
    for (int i = 0; i < NumberOfOranges; ++i)
    {
        // Read the size of the current orange.
        unsigned int orange = 0;
        std::cin >> orange;

        // If the orange size exceeds MaxSize, it cannot be juiced, so skip this orange.
        if (orange > MaxSize)
        {
            continue; // Move to the next orange in the loop.
        }

        // Add the size of the orange to the accumulated waste (SumOfOranges).
        SumOfOranges += orange;

        // If the total waste exceeds the WasteSize, empty the juicer.
        if (SumOfOranges > WasteSize)
        {
            Empty++; // Increment the empty counter as the juicer is being emptied.
            SumOfOranges = 0; // Reset the waste size to 0 after emptying the juicer.
        }
    }

    // Output the total number of times the juicer was emptied.
    std::cout << Empty << std::endl;

    return 0; // End of program.
}
