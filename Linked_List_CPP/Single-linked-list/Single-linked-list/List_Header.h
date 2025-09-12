//#pragma once
#ifndef __LIST_HEADER
enum options {
	DISPLAY = 1,
	COUNT,
	SEARCH,
	ADD_BEGIN,
	ADD_END,
	ADD_AFTER,
	ADD_BEFORE,
	ADD_POS,
	DELETE,
	REVERSE,
	QUIT
};


class Node {
public:
	int data;
	Node* next;
	static int nodeCount;
	Node() : data(0), next(nullptr) {}

	Node(int val) : data(val), next(nullptr) {
		nodeCount++;
	}

	~Node() {
		nodeCount--;
	}

	int getNodeCount() const {
		return nodeCount;
	}
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() : head(nullptr) {}
	LinkedList(int val);
	~LinkedList();
	void insertAtEnd(int val);
	void insertAtHead(int val);
	void insertAfter(int after, int val);
	void insertBefore(int before, int val);
	void insertAtPos(int pos, int val);
	void deleteNode(int val);
	void reverse();
	void searchNode(int val) const;
	void display() const;
	void Count() const;
};
#endif // !__LIST_HEADER
