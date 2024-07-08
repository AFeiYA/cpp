
// What is Queue?
// Queue is a linear data structure that stores items in First In First Out (FIFO) manner.
// A good example of queue is any queue of consumers for a resource where the consumer that came first is served first.
#include <iostream>
class Queue {
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    Queue() {
		front = rear = -1;
		size = 10;
		Q = new int[size];
	}
    Queue(int size) {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }    
    void enqueue(int x);
    int dequeue();
    void Display();
};
void Queue::enqueue(int x) {
    if (rear == size - 1) {
		std::cout << "Queue is full" << std::endl;
	}
    else {
		rear++;
		Q[rear] = x;
	}
}
int Queue::dequeue() {
	int x = -1;
    if (front == rear) {
		std::cout << "Queue is empty" << std::endl;
	}
    else {
		front++;
		x = Q[front];
	}
	return x;
}
void Queue::Display() {
    for (int i = front + 1; i <= rear; i++) {
		std::cout << Q[i] << " ";
	}
	std::cout << std::endl;
}




int main()
{
    Queue q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.Display();
	q.enqueue(60);
	return 0;
}
