#include <string>
#include "MergeSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()
    throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
//REF: http://www.geeksforgeeks.org/merge-sort-for-linked-list/
//REF: http://algorithms.tutorialhorizon.com/merge-sort-in-a-linked-list/

void MergeSort::mergesort(LinkedList& list)
{
    /***** Complete this member function. *****/
    if(list.get_head() != NULL && list.get_head()->next != NULL) {
		compare_count++;
		LinkedList list1;
		LinkedList list2;
		list.split(list1, list2);
		mergesort(list1);
		mergesort(list2);
		merge(list, list1, list2);
	}

}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */

//Ref: Datastructures by Malik  Chapter 10: Sorting Algorithms

void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
	if(sublist1.get_size() == 0)
	{
		list = sublist2;
		return;
	}
	else if(sublist2.get_size() == 0)
	{
		list = sublist1;
		return;
	}
	LinkedList newList;
	Node *tempHead;

	Node *head1 = sublist1.get_head();
	Node *head2 = sublist2.get_head();

	if(head1->element.get_value() <= head2->element.get_value()) {
		move_count++;
		compare_count++;
		tempHead = head1;
		head1 = head1->next;
		newList.set(tempHead,tempHead,1);
	} else {
		move_count++;
		compare_count++;
		tempHead = head2;
		head2 = head2->next;
		newList.set(tempHead,tempHead,1);
	}

	while(head1 && head2)
	{
		if(head1->element.get_value() <= head2->element.get_value()) {
			move_count++;
			compare_count++;
			tempHead = head1;
			head1=head1->next;
			newList.add(tempHead);
		} else {
			move_count++;
			compare_count++;
			tempHead = head2;
			head2=head2->next;
			newList.add(tempHead);
		}
	}

	while(head1 != NULL)
	{
		move_count++;
		tempHead = head1;
		head1 = head1->next;
		newList.add(tempHead);
	}
	while(head2 != NULL)
	{
		move_count++;
		tempHead = head2;
		head2 = head2->next;
		newList.add(tempHead);
	}
	list = newList;

}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }
