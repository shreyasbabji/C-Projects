#include <iostream>
#include "QuickSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */

//Ref: own implementation but refered below link
 //http://www.programcreek.com/2012/11/quicksort-array-in-java/

void QuickSorter::quicksort(const int left, const int right)
{
	compare_count++;
	Element pivot = choose_pivot(left,right);
	int index = partition(left, right,pivot);
	if (left < index - 1){
		quicksort(left, index - 1);
		compare_count++;
	}
	if (index < right){
		quicksort(index, right);
		compare_count++;
	}
}


/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */

//Ref: own implementation but referred below link
//REF: http://www.programcreek.com/2012/11/quicksort-array-in-java/

int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
    /***** Complete this member function. *****/
    	int i = left, j = right;
	int tmp;
	while (i <= j) {
		compare_count++;
		while (data[i] < pivot){
			i++;
			compare_count++;
		}
		while (data[j] > pivot){
			j--;
			compare_count++;
		}

		if (i <= j)
		{
			swap(i,j);
			i++;
			j--;
		}
	};
	return i;

}
