#include "List_Header.h"
#include<iostream>

int Node::nodeCount = 0;

LinkedList::LinkedList(int count) {
	for (int i = 0; i < count; i++) {
		int value;
		std::cout << "Enter value for node " << (i + 1) << ": ";
		std::cin >> value;
		insertAtEnd(value);
	}
}

void LinkedList::insertAtHead(int value) {
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
}

void LinkedList::insertAtEnd(int value) {
	Node* newNode = new Node(value);
	if (head == nullptr) {
		head = newNode;
		return;
	}

	Node* temp = head;

	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
}


void LinkedList::insertAfter(int after, int value) {
	Node* temp = head;

	while (temp != nullptr && temp->data != after) {
		temp = temp->next;
	}

	if (temp == nullptr) {
		std::cout << "Node with value " << after << " not found." << std::endl;
		return;
	}

	if (temp->data == after) {
		Node* newNode = new Node(value);
		newNode->next = temp->next;
		temp->next = newNode;
	}
	else {
		std::cout << "Node with value " << after << " not found." << std::endl;
	}
}


void LinkedList::insertBefore(int before, int value)
{
	if (head == nullptr) {
		std::cout << "List is empty." << std::endl;
		return;
	}
	if (head->data == before) {
		insertAtHead(value);
		return;
	}
	Node* temp = head;

	while (temp->next != nullptr && temp->next->data != before) {
		temp = temp->next;
	}
	if (temp->next == nullptr) {
		std::cout << "Node with value " << before << " not found." << std::endl;
		return;
	}
	Node* newNode = new Node(value);
	newNode->next = temp->next;
	temp->next = newNode;
}


void LinkedList::insertAtPos(int pos, int value) {
	if (pos <= 0) {
		std::cout << "Position should be >= 1." << std::endl;
		return;
	}
	if (pos == 1) {
		insertAtHead(value);
		return;
	}
	Node* temp = head;
	for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
		temp = temp->next;
	}
	if (temp == nullptr) {
		std::cout << "Position " << pos << " is out of bounds." << std::endl;
		return;
	}
	Node* newNode = new Node(value);
	newNode->next = temp->next;
	temp->next = newNode;
}

void LinkedList::deleteNode(int value) {

	if (head == nullptr) {
		std::cout << "List is empty." << std::endl;
		return;
	}
	if (head->data == value) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	Node* ptr = head;
	Node* temp = nullptr;

	while (ptr->next != nullptr) {
		if (ptr->next->data == value) {
			temp = ptr->next;
			ptr->next = temp->next;
			delete temp;
			break;
		}
	}

	if (ptr->next == nullptr) {
		std::cout << "Node with value " << value << " not found." << std::endl;
	}
}

void LinkedList::reverse() {
	Node* prevNode = nullptr, * currentNode = head, * nextNode = nullptr;

	while (currentNode != nullptr) {
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
	head = prevNode;
}

void LinkedList::searchNode(int data) const {
	Node* temp = head;
	int pos = 1;
	while (temp != nullptr) {
		if (temp->data == data) {
			std::cout << "Element " << data << " found at position : " << pos << std::endl;
			break;
		}
		temp = temp->next;
		pos++;
	}

	if (temp == nullptr) {
		std::cout << "Element " << data << " not found in the list." << std::endl;
	}
}

void LinkedList::display() const {
	Node* temp = head;
	while (temp != nullptr) {
		std::cout << temp->data << " -> ";
		temp = temp->next;
	}
	std::cout << "nullptr" << std::endl;
}

LinkedList::~LinkedList() {
	Node* current = head;
	while (current != nullptr) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

void LinkedList::Count() const {
	std::cout << "Total nodes: " << head->getNodeCount() << std::endl;
}