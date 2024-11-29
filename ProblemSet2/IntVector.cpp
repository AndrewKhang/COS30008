#include "IntVector.h"#include "IntVector.h"
#include <stdexcept>    // For std::out_of_range

// Constructor: Initializes the vector by copying the input array
IntVector::IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
{
    fNumberOfElements = aNumberOfElements;  // Store the number of elements
    fElements = new int[fNumberOfElements];  // Allocate memory for elements

    // Copy elements from input array to fElements
    for (size_t i = 0; i < fNumberOfElements; i++)
    {
        fElements[i] = aArrayOfIntegers[i];
    }
}

// Destructor: Frees the allocated memory
IntVector::~IntVector()
{
    delete[] fElements;  // Release allocated memory
}

// Returns the number of elements in the vector
size_t IntVector::size() const
{
    return fNumberOfElements;
}

// Returns the element at the specified index, throws an exception if out of bounds
const int IntVector::get(size_t aIndex) const
{
    return (*this)[aIndex];  // Use the indexer to access the element
}

// Swaps the elements at the specified indices, throws an exception if out of bounds
void IntVector::swap(size_t aSourceIndex, size_t aTargetIndex)
{
    if (aSourceIndex >= fNumberOfElements || aTargetIndex >= fNumberOfElements)
    {
        throw std::out_of_range("Illegal vector indices");
    }

    // Perform the swap
    int temp = fElements[aSourceIndex];
    fElements[aSourceIndex] = fElements[aTargetIndex];
    fElements[aTargetIndex] = temp;
}

// Overloaded indexer: Returns the element at the specified index (with bounds checking)
const int IntVector::operator[](size_t aIndex) const
{
    if (aIndex >= fNumberOfElements)
    {
        throw std::out_of_range("Illegal vector index");
    }
    return fElements[aIndex];
}
