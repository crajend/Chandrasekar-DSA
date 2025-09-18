// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct List{
        int info;
        struct List* link;
}LINKED_LIST;

void displayList(LINKED_LIST *head)
{
    if(head == NULL) {
        printf("List is Empty\n");
        return;
    }
    
    for(LINKED_LIST *p=head; p!=NULL; p=p->link) {
        printf("%d -> ", p->info);
    }
    
    printf("NULL\n");
}


LINKED_LIST *insertInOrder(LINKED_LIST* head, int data) 
{
    LINKED_LIST* temp, *p;
    
    temp = (LINKED_LIST*) malloc (sizeof(LINKED_LIST));
    temp->info = data;
    
    if( (head == NULL) || (head->info >= data))
    {
        temp->link = head;
        head = temp;
    } else {
        
        for(p=head; p != NULL; p=p->link) {
            if((p->link == NULL) || (p->link->info >= data)) {
                temp->link = p->link;
                p->link = temp;
                break;
            }
        }
    }
    return head;
}

LINKED_LIST *create_SortedList(LINKED_LIST* head)
{
    int i,n,data;
    
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    
    for(i=1; i<=n; i++) {
        printf("%s",(i==1) ? "\nEnter the first element : " : "\nEnter the next element : ");
        scanf("%d",&data);
        head = insertInOrder(head,data);
    }
    
    return head;
}

LINKED_LIST* merge_SortedList(LINKED_LIST *p1, LINKED_LIST *p2)
{
    LINKED_LIST *temp, *headM, *pM;
    
    temp = (LINKED_LIST*)malloc(sizeof(LINKED_LIST));
    temp->link =NULL;
    
    headM=temp;
    
    if(p1->info <= p2->info) {
        temp->info = p1->info;
        p1=p1->link;
    } else {
        temp->info = p2->info;
        p2=p2->link;
    }
    
    pM=headM;
    
    
    while((p1 != NULL) && (p2 != NULL)) {
        
        temp = (LINKED_LIST*)malloc(sizeof(LINKED_LIST));
        temp->link =NULL;
        
        if(p1->info <= p2->info) {
            temp->info = p1->info;
            p1=p1->link;
            pM->link = temp;
            pM=temp;
        } else {
            temp->info = p2->info;
            p2=p2->link;
            pM->link = temp;
            pM = temp;
        }
    }
    
    while(p1 !=NULL) {
        temp = (LINKED_LIST*)malloc(sizeof(LINKED_LIST));
        temp->info = p1->info;
        temp->link =NULL;
        pM->link=temp;
        pM=temp;
        
        p1 = p1->link;
    } 
    
    while(p2 != NULL){
        temp = (LINKED_LIST*)malloc(sizeof(LINKED_LIST));
        temp->info = p2->info;
        temp->link =NULL;
        pM->link=temp;
        pM=temp;
        
        p2 = p2->link;
    }
    
    
    return headM;
}

int main() {
    LINKED_LIST *list1=NULL;
    LINKED_LIST *list2=NULL;
    LINKED_LIST *listM=NULL;
    
    list1=create_SortedList(list1);
    list2=create_SortedList(list2);
    
    displayList(list1);
    displayList(list2);
    
    listM = merge_SortedList(list1,list2);
    printf("\nMerged Sorted List : ");
    displayList(listM);
    return 0;
}