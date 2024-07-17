#ifndef HEAP_A_H
#define HEAP_A_H

#include <vector>
class Heap_A
{
public:
	Heap_A();
	void insert(int n);
	int extractMax();
	void heapSort(std::vector<int>& arr);
private:
	std::vector<int> heap;
	void heapifyUp(int index);
	void heapifyDown(int index);
	void buildMaxHeap(std::vector<int>& arr);
	void heapify(std::vector<int>& arr, int n, int i);
};

#endif // HEAP_A_H
