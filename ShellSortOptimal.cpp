#include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */

//Ref: http://algs4.cs.princeton.edu/21elementary/Shell.java

void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
    	int n = data.size();
	int h = 1;

	while (h < n/3) {
		h = 3*h + 1;
	}

	while (h >= 1) {
		for (int i = h; i < n; i++) {
			for (int j = i; j >= h && (data[j] < data[j-h]); j -= h) {
				swap( j, j-h);
			}
			compare_count++;
		}
		h /= 3;
	}

}
