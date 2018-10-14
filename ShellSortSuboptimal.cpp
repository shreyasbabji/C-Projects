#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
//Ref:  https://www.cise.ufl.edu/~sahni/dsaaj/enrich/c2/shell.htm

void ShellSortSuboptimal::run_sort_algorithm() throw (string){
	int n = data.size();
	for (int gap = n/2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			Element temp = data[i];
			int j;
			for (j = i; j >= gap && data[j - gap] > temp; j -= gap){
				data[j] = data[j - gap];
				move_count += 1;
				compare_count++;
			}
			compare_count++;
			data[j] = temp;
		}
	}
}
