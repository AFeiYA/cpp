

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

class CircularQueue {
	private:
		int size;
		int front;
		int rear;
		int* Q;
	public:
		CircularQueue() {
			front = rear = 0;
			size = 10;
			Q = new int[size];
		}
		CircularQueue(int size) {
			front = rear = 0;
			this->size = size;
			Q = new int[this->size];
		}
		void enqueue(int x);
		int dequeue();
		void Display();
};

void CircularQueue::enqueue(int x) {
	if ((rear + 1) % size == front) {
		std::cout << "Queue is full" << std::endl;
	}
	else {
		rear = (rear + 1) % size;
		Q[rear] = x;
	}
}
int CircularQueue::dequeue() {
	int x = -1;
	if (front == rear) {
		std::cout << "Queue is empty" << std::endl;
	}
	else {
		front = (front + 1) % size;
		x = Q[front];
	}
	return x;
}
void CircularQueue::Display() {
	int i = front + 1;
	do {
		std::cout << Q[i] << " ";
		i = (i + 1) % size;
	} while (i != (rear + 1) % size);
	std::cout << std::endl;
}

int main()
{
    CircularQueue q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.Display();
	q.dequeue();
	q.Display();
	q.dequeue();
	q.Display();
	q.enqueue(60);
	q.Display();
	q.enqueue(70);
	q.Display();

	return 0;
}
