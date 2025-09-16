#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *link;
}LINKED_LIST;


enum options {
    DISPLAY = 1,
    INSERT,
    QUIT
};


void displayList(LINKED_LIST *head)
{
    LINKED_LIST *p;
    
    if(head != NULL) {
        
        for(p=head; p!=NULL; p=p->link)
            printf("%d -> ", p->info);
        printf("NULL\n");
    }
    else {
        printf("List is Empty\n");
    }
}

void searchNode(LINKED_LIST *head)
{
    LINKED_LIST *p;
    int n=0,data;
    
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    
    printf("Enter the element to searched : ");
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



LINKED_LIST *insertInOrder(LINKED_LIST *head, int data)
{
    LINKED_LIST *temp, *p;
    
    temp = (LINKED_LIST*)malloc(sizeof(LINKED_LIST));
    temp->info = data;
    
    if( (head == NULL) || (data < head->info))
    {
        temp->link = head;
        head = temp;
        return head;
    }
    
    p=head;
    
    while( (p->link!=NULL) && (p->link->info <= data))
        p=p->link;
        
    temp->link=p->link;
    p->link = temp;
    
    return head;
}

int main() {
	// your code goes here
    LINKED_LIST *head = NULL;
    int choice,data,val,pos;
    

    while(1) {
        printf("\n1.Display list\n");
        printf("2.Insert a new node\n");
        printf("3.Search an element in sorted list\n");
        printf("4.Quit\n");
        
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
            case INSERT:    printf("\nEnter the element : ");
                            scanf("%d",&data);
                            head = insertInOrder(head,data);
                            break;
            default:        break;
        }
    }
}