#include <stdio.h>


typedef struct Node{
    int info;
    struct Node *link;
}LINKED_LIST;


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

int main() {
    LINKED_LIST *start = NULL;
    int choice,data,x,k;
    
    while(1) {
        printf("\n1.Display list\n");
        printf("2.Count of Nodes\n");
        printf("3.Search an element in list\n");
        printf("4.Add to empty list / Add to beginning\n");
        printf("5.Add a node at end of the list\n");
        printf("6.Add after a specified node\n");
        printf("7.Add before a specified node\n");
        printf("8.Add a node at given position\n");
        printf("9.Delete a node\n");
        printf("10.Reverse the list\n");
        printf("11.Quit\n");
        
        printf("Enter your choice : ");
        
        scanf("%d",&choice);
        getchar();
        
        if(choice == QUIT) {
            printf("\nBye.. Bye...\n");
            break;
        }
        
        switch(choice) {
            case DISPLAY: break;
            case COUNT: break;
            case SEARCH: break;
            case ADD_BEGIN: break;
            case ADD_END: break;
            case ADD_AFTER: break;
            case ADD_BEFORE: break;
            case ADD_POS: break;
            case DELETE: break;
            case REVERSE: break;
            default: break;
        }
    }
}
