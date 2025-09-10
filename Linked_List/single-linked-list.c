#include <stdio.h>
#include <stdlib.h>

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

void displayList(LINKED_LIST *head)
{
    LINKED_LIST *p;
    
    for(p=head; p!=NULL; p=p->link)
        printf("%d -> ", p->info);
    printf("NULL\n");
}


void countNodes(LINKED_LIST *head)
{
    LINKED_LIST *p;
    int n=0;
    
    for(p=head; p!=NULL; p=p->link)
        n++;

    printf("Number of nodes in the list : %d\n",n);
}


void searchNode(LINKED_LIST *head)
{
    LINKED_LIST *p;
    int n=0,data;
    
    printf("Enter the element to serached : ");
    scanf("%d",&data);
    
    for(p=head; p!=NULL; p=p->link) {
        n++;
        
        if(p->info == data)
            break;
    }

    if(p != NULL) 
        printf("Number found at position %d in the list\n",n);
    else
        printf("Number not found in the list\n");
}

LINKED_LIST *insertAtBegin(LINKED_LIST *head,int data)
{
    LINKED_LIST *temp = (LINKED_LIST*)malloc(sizeof(LINKED_LIST));
    
    temp->info = data;
    temp->link = head;
    head = temp;
    
    return head;
}

void insertAtEnd(LINKED_LIST *head,int data)
{
    LINKED_LIST *temp = (LINKED_LIST*)malloc(sizeof(LINKED_LIST));
    LINKED_LIST *p;
    
    temp->info = data;
    temp->link = NULL;
    
    if(head != NULL) {
        p=head;
        while(p->link != NULL)
            p=p->link;
            
        p->link = temp;
    }
    else {
        head=temp;
    }
    
}

LINKED_LIST *create_list(LINKED_LIST *head)
{
    int i,n,data;
    printf("\nEnter the number of nodes to created : ");
    scanf("%d",&n);
    
    if(n==0)
        return head;
        
    printf("\nEnter the first element to be inserted : ");
    scanf("%d",&data);
    
    head=insertAtBegin(head, data);
    
    for(i=2; i<=n; i++) {
        printf("\nEnter the next element to be inserted : ");
        scanf("%d",&data);
        insertAtEnd(head,data);
    }
    
    return head;
}

int main() {
	// your code goes here
    LINKED_LIST *head = NULL;
    int choice,data,x,k;
    
    head = create_list(head);
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
            case DISPLAY:   displayList(head);
                            break;
            case COUNT:     countNodes(head); 
                            break;
            case SEARCH:    searchNode(head);
                            break;
            case ADD_BEGIN: printf("\nEnter the element to be inserted at beginning: ");
                            scanf("%d",&data);
                            head = insertAtBegin(head, data);
                            break;
            case ADD_END:   printf("\nEnter the element to be inserted at end: ");
                            scanf("%d",&data);
                            insertAtEnd(head, data);
                            break;
            case ADD_AFTER: 
            break;
            case ADD_BEFORE: 
            break;
            case ADD_POS: 
            break;
            case DELETE: 
            break;
            case REVERSE: 
            break;
            default: 
            break;
        }
    }
}

