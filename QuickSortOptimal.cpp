#include "QuickSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSortOptimal::QuickSortOptimal(string name) : QuickSorter(name) {}

/**
 * Destructor.
 */
QuickSortOptimal::~QuickSortOptimal() {}

/**
 * Choose a good pivot, the median-of-three:
 * The middle value of the leftmost, rightmost, and center elements.
 * This is a compromise since the most optimal pivot would be the
 * median of the subrange, but that's too expensive to compute.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */

// Ref: http://stackoverflow.com/questions/1582356/fastest-way-of-finding-the-middle-value-of-a-triple

Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
    /***** Complete this member function. *****/
    int middle = ( left + right ) /2 ;
	if (data[left] > data[right])
	{
		compare_count+=2;
		if (data[right] > data[middle])
		{
			return data[right];
		}
		else if (data[left] > data[middle])
		{
			return data[middle];
		}
		else
		{
			return data[left];
		}
	}
	else
	{
		compare_count+=2;
		if (data[left] > data[middle])
		{
			return data[left];
		}
		else if (data[right] > data[middle])
		{
			return data[middle];
		}
		else
		{
			return data[right];
		}

	}

}
