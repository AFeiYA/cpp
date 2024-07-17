#include "Heap_A.h"
#include <iostream>

Heap_A::Heap_A() {}

void Heap_A::insert(int key) {
    heap.push_back(key);
    heapifyUp(heap.size() - 1);
}

int Heap_A::extractMax() {
    if (heap.empty()) {
        std::cerr << "Heap is empty\n";
        return -1;
    }
    int max = heap.front();
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return max;
}

void Heap_A::heapifyUp(int index) {
    while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
        std::swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void Heap_A::heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap.size() && heap[left] > heap[largest])
        largest = left;

    if (right < heap.size() && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        std::swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

void Heap_A::buildMaxHeap(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void Heap_A::heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void Heap_A::heapSort(std::vector<int>& arr) {
    buildMaxHeap(arr);
    for (int i = arr.size() - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
