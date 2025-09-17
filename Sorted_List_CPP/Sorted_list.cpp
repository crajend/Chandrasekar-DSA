// Sorted_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Sort_List.h"

int main()
{
	Sort_List list;
	int choice, data;

	while (1) {
		std::cout << "\nMenu:\n";
		std::cout << "1. Display list\n";
		std::cout << "2. Insert in order\n";
		std::cout << "3. Search list\n";
		std::cout << "4. Quit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		switch (choice) {
		case DISPLAY:
			list.displayList();
			break;
		case INSERT:
			std::cout << "Enter value to insert: ";
			std::cin >> data;
			list.insertInOrder(data);
			break;
		case SEARCH:
			std::cout << "Enter value to search: ";
			std::cin >> data;
			list.searchList(data);
			break;
		case QUIT:
			std::cout << "Exiting program." << std::endl;
			return 0;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
		}
	}
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
