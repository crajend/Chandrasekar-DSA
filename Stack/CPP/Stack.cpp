// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Stack {
private:
    int* arr;
    int top;
    int capacity;
public:
    Stack(int size = 10) : arr(new int(size)), top(-1), capacity(size){}
    
    ~Stack() {
        capacity = 0;
        top = -1;
        delete[] arr;
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void push(int x) {
        arr[++top] = x;
    }

    int pop() {
        return arr[top--];
    }

    void display() const {
        for (int i = 0; i <= top; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }

    int peek() const {
        return arr[top];
	}
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    std::cout << "Top element is: " << s.peek() << "\n";
    s.pop();
    s.display();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
