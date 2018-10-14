#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}



/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
//Ref: Implemented using http://www.cplusplus.com/forum/beginner/3322/
void InsertionSort::run_sort_algorithm() throw (string)
{
//    /***** Complete this member function. *****/
	int N = data.size();
	int i, j;


	for (i = 1; i< N; i++)
	{
		j = i;
		Element temp = data[i];
		while (j > 0 && temp < data[j-1])
		{
			compare_count++;
			move_count += 1;
			data[j] = data[j-1];
			j = j-1;
		}
		data[j] = temp;
		compare_count++;

	}

}

