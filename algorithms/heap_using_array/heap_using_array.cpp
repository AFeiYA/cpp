#include <iostream>
#include "heap_a.h"

int main()
{
	Heap_A heap;
	std::vector<int> arr = { 4, 10, 3, 5, 1 };
	heap.heapSort(arr);
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	return 0;
}
