#include "Sort_List.h"
#include<iostream>

int Node::nodeCount = 0;

Sort_List::~Sort_List()
{
	Node* current = head;
	while (current != nullptr) {
		Node* temp = current;
		current = current->link;
		free(temp);
	}
}

void Sort_List::displayList() const
{
	Node* current = head;

	while (current != nullptr) {
		std::cout << current->info << " -> ";
		current = current->link;
	}

	std::cout << "nullptr" << std::endl;
}


void Sort_List::insertInOrder(int data)
{
	if (head == nullptr || data < head->info) {
		head = new Node(data, head);
		return;
	}

	for (Node* current = head; current != nullptr; current = current->link) {
		if (current->link == nullptr || data <= current->link->info) {
			current->link = new Node(data, current->link);
			return;
		} 
	}
}


void Sort_List::searchList(int data) const
{
	Node* current = head;
	int pos = 0;

	if (head == nullptr) {
		std::cout << "List is empty." << std::endl;
		return;
	}


	while (current != nullptr) {
		if (current->info == data) {
			std::cout << data << " found in position " << pos << std::endl;
			return;
		}
		current = current->link;
		pos++;
	}
	std::cout << data << " not found in the list." << std::endl;
}
