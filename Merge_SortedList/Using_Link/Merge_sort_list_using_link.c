// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

typedef struct LinkedList{
    int info;
    struct LinkedList *link;
}LINKED_LIST;


void displayList(LINKED_LIST *head) {
    LINKED_LIST *temp;
    
    for(temp=head; temp != NULL; temp = temp->link)
        printf("%d -> ", temp->info);
        
    printf("NULL\n");
}

LINKED_LIST *insertInOrder(LINKED_LIST *head, int data)
{
    LINKED_LIST *temp,*p;
    
    temp = (LINKED_LIST*)malloc(sizeof(LINKED_LIST));
    temp->info = data;
    
    if((head == NULL) || (head->info >= data)) {
       temp->link = head;
       head = temp;
       return head;
    }
    
    for(p=head; p->link != NULL; p = p->link) {
        if(p->link->info > data)
            break;
    }
    
    temp->link = p->link;
    p->link = temp;
    
    return head;
}

LINKED_LIST *createSortList(LINKED_LIST *head) {
    int i,n,data;
    
    printf("\nEnter the number of nodes : ");
    scanf("%d",&n);
    
    for(i=0; i<n; i++) {
        printf("%s", (i==0) ? "\nEnter the first element : " : 
                              "\nEnter the next element : ");
        scanf("%d",&data);
        head = insertInOrder(head, data);
    }
    
    return head;
}


LINKED_LIST* mergeList(LINKED_LIST* list1, LINKED_LIST* list2) {
    
    LINKED_LIST *p1=list1, *p2=list2, *pM=NULL, *headM=NULL;
    
    if(p1->info <= p2->info) {
        headM = p1;
        p1 = p1->link;
    } else {
        headM = p2;
        p2 = p2->link;
    }
    
    pM = headM;
    while((p1!= NULL)&&(p2!=NULL)){
        if(p1->info <= p2->info) {
            pM->link = p1;
            pM = pM->link;
            p1 = p1->link;
        } else {
            pM->link = p2;
            pM = pM->link;
            p2 = p2->link;
        }
    }
    
    if(p1 != NULL) {
        pM->link = p1;
    } 
    
    if(p2 != NULL) {
        pM->link = p2;
    }
    
    return headM;
}

int main() {
    LINKED_LIST *list1=NULL,*list2=NULL,*listM;
    list1 = createSortList(list1);
    list2 = createSortList(list2);
    
    displayList(list1);
    displayList(list2);
    
    listM = mergeList(list1, list2);
    
    
    displayList(listM);
    return 0;
}