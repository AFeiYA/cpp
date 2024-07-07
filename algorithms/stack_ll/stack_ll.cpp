#include <iostream>
#include <string>

// Template class for Node
template <class T>
class Node {
public:
    T data;
    Node* next;
};

// Template class for Stack
template <class T>
class Stack {
public:
    Node<T>* top;
    Stack() { top = NULL; }
    void push(T x);
    T pop();
    void Display();
    int isEmpty();
    T peek();
};

template <class T>
void Stack<T>::push(T x) {
    Node<T>* t = new Node<T>;
    if (t == NULL) {
        std::cout << "Stack is full" << std::endl;
    }
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

template <class T>
T Stack<T>::pop() {
    if (top == NULL) {
        std::cout << "Stack is empty" << std::endl;
        return -1; // Return an invalid value for error indication
    }
    else {
        Node<T>* t = top;
        T x = t->data;
        top = top->next;
        delete t;
        return x;
    }
}

template <class T>
void Stack<T>::Display() {
    Node<T>* p = top;
    while (p) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

template <class T>
int Stack<T>::isEmpty() {
    return top == NULL;
}

template <class T>
T Stack<T>::peek() {
    if (top != NULL) {
        return top->data;
    }
    return -1; // Return an invalid value for error indication
}

int isOperand(char c) {
    return !(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')');
}

int outStackPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 3;
    }
    else if (c == '^') {
        return 6;
    }
    else if (c == '(') {
        return 7;
    }
    else if (c == ')') {
        return 0;
    }
    return -1; // Error case
}

int inStackPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 2;
    }
    else if (c == '*' || c == '/') {
        return 4;
    }
    else if (c == '^') {
        return 5;
    }
    else if (c == '(') {
        return 0;
    }
    return -1; // Error case
}

std::string InfixToPostfix(std::string infix) {
    Stack<char> stk;
    std::string postfix;
    for (size_t i = 0; i < infix.length(); i++) {
        if (isOperand(infix[i])) {
            postfix += infix[i];
        }
        else if (infix[i] == '(') {
            stk.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (!stk.isEmpty() && stk.peek() != '(') {
                postfix += stk.pop();
            }
            stk.pop(); // Pop the '(' from stack
        }
        else {
            while (!stk.isEmpty() && outStackPrecedence(infix[i]) <= inStackPrecedence(stk.peek())) {
                postfix += stk.pop();
            }
            stk.push(infix[i]);
        }
    }
    while (!stk.isEmpty()) {
        postfix += stk.pop();
    }
    return postfix;
}

int evaluatePostfix(std::string postfix) {
	Stack<int> stk;
    for (size_t i = 0; i < postfix.length(); i++) {
        if (isOperand(postfix[i])) {
			stk.push(postfix[i] - '0');
		}
        else {
			int x2 = stk.pop();
			int x1 = stk.pop();
            switch (postfix[i]) {
			case '+':
				stk.push(x1 + x2);
				break;
			case '-':
				stk.push(x1 - x2);
				break;
			case '*':
				stk.push(x1 * x2);
				break;
			case '/':
				stk.push(x1 / x2);
				break;
			case '^':
				stk.push(pow(x1, x2));
				break;
			}
		}
	}
	return stk.pop();
}

int main() {
    std::string infix = "(1+2)*(3^2-5)/2+2^2";
    std::cout << "Postfix: " << InfixToPostfix(infix) << std::endl;
    std::string postfix = InfixToPostfix(infix);
    std::cout << "Evaluation: " << evaluatePostfix(postfix) << std::endl;
    return 0;
}
