// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List_Header.h"
int main()
{
    std::cout << "\nEnter the numbers of nodes : ";
    int nodeCount;
    std::cin >> nodeCount;
    LinkedList list(nodeCount);
    while (1) {
        std::cout << "\n1.Display list\n";
        std::cout << "2.Count of Nodes\n";
        std::cout << "3.Search an element in list\n";
        std::cout << "4.Add to empty list / Add to beginning\n";
        std::cout << "5.Add a node at end of the list\n";
        std::cout << "6.Add after a specified node\n";
        std::cout << "7.Add before a specified node\n";
        std::cout << "8.Add a node at given position\n";
        std::cout << "9.Delete a node\n";
        std::cout << "10.Reverse the list\n";
        std::cout << "11.Quit\n";

        std::cout << "Enter your choice : ";
        int choice, data, val, pos;

        std::cin >> choice;

        if (choice == QUIT) {
            std::cout << "\nBye.. Bye...\n";
            break;
        }

        switch (choice) {
        case DISPLAY:   list.display();
            break;
        case COUNT:     list.Count();
            break;
        case SEARCH:    std::cout << "\nEnter the element to be searched: ";
            std::cin >> data;
            list.searchNode(data);
            break;
        case ADD_BEGIN: std::cout << "\nEnter the element to be inserted at beginning: ";
            std::cin >> data;
            list.insertAtHead(data);
            break;
        case ADD_END:   std::cout << "\nEnter the element to be inserted at end: ";
            std::cin >> data;
            list.insertAtEnd(data);
            break;
        case ADD_AFTER: std::cout << "\nEnter the element to be inserted : ";
            std::cin >> data;
            std::cout << "\nEnter after which element the value should be inserted : ";
            std::cin >> val;
            list.insertAfter(val, data);
            break;
        case ADD_BEFORE: std::cout << "\nEnter the element to be inserted : ";
            std::cin >> data;
            std::cout << "\nEnter before which element the value should be inserted : ";
            std::cin >> val;
            list.insertBefore(val, data);
            break;
        case ADD_POS:  std::cout << "\nEnter the element to be inserted : ";
            std::cin >> data;
            std::cout << "\nEnter the position the value should be inserted : ";
            std::cin >> pos;
            list.insertAtPos(pos, data);
            break;
        case DELETE:   std::cout << "\nEnter the data to be deleted: ";
            std::cin >> data;
            list.deleteNode(data);
            break;
        case REVERSE:  std::cout << "Before reversing the list : ";
            list.display();
            std::cout << "After reversing the list : ";
            list.reverse();
            list.display();
        default:
            break;
        }
    }
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
