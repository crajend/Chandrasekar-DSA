#pragma once
enum options {
    DISPLAY = 1,
    INSERT,
    SEARCH,
    QUIT
};

class Node {
public:
    int info;
    Node* link;
    static int nodeCount;

    Node() : info(0), link(nullptr) {
        nodeCount++;
    }

    Node(int data, Node* next = nullptr) : info(data), link(next) {
        nodeCount++;
    }

    ~Node() {
        nodeCount--;
    }

    int getNodeCount() const {
        return nodeCount;
    }
};

class Sort_List
{
private:
    Node* head;

public:
    Sort_List() : head(nullptr) {}
	Sort_List(int data) : head(new Node(data)) {}
    ~Sort_List();
    void displayList() const;
    void insertInOrder(int data);
    void searchList(int data) const;
};

