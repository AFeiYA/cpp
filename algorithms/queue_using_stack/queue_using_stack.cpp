//

#include <iostream>
#include <stack>
// how to implement a queue using two stacks
// enqueue: O(1)
// dequeue: O(n)
// space: O(n)
class Queue {
    private:
	std::stack<int> s1;
	std::stack<int> s2;
	public:
		void enqueue(int x) {
		s1.push(x);
		}
		int dequeue() {
		int x = -1;
		if (s2.empty()) {
			if (s1.empty()) {
				std::cout << "Queue is empty" << std::endl;
				return x;
			}
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		x = s2.top();
		s2.pop();
		return x;
		}
};


int main()
{
    Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
}

