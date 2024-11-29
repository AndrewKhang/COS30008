#include "SortableIntVector.h"

// Constructor: Uses the base class constructor
SortableIntVector::SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
    : IntVector(aArrayOfIntegers, aNumberOfElements)  // Call the base class constructor
{
}

// Bubble Sort implementation with a custom lambda function
void SortableIntVector::sort(Comparable aOrderFunction)
{
    size_t n = size();
    bool swapped = true;

    // Bubble Sort algorithm
    while (swapped)
    {
        swapped = false;
        for (size_t i = 1; i < n; ++i)
        {
            // Use the provided lambda function to compare elements
            if (!aOrderFunction(get(i ), get(i -1 )))
            {
                swap(i - 1, i);  // Swap if the order is incorrect
                swapped = true;
            }
        }
        n--;  // Each pass places the largest element at the end, so reduce the range
    }
}
