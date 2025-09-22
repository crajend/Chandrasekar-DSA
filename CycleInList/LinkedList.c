// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
}DOUBLE_LIST;


void displayList(struct node *head) {
    struct node *temp;
    
    for(temp=head; temp != NULL; temp = temp->link)
        printf(" %d -> ", temp->info);
        
    printf("NULL\n");
}


struct node *create_list(struct node *head)
{
    struct node *p,*temp;
    int i,n,data;
    
    printf("\nEnter the number of nodes : ");
    scanf("%d",&n);
    
    printf("\nEnter the [1] element : ");
    scanf("%d",&data);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = head;
    head = temp;
    
    p= head;
    
    for(i=1; i<n; i++) {
        printf("\nEnter the [%d] element : ",i+1);
        scanf("%d",&data);
        temp = (struct node*)malloc(sizeof(struct node));
        temp->info = data;
        temp->link = NULL;
        p->link = temp;
        p = p->link;
    }
    
    return head;
}

void insertCycle(struct node *list, int x)
{
    struct node *p=list,*prev, *px;
    
    while(p != NULL) {
        
        if(p->info == x)
            px = p;
            
        prev = p;
        p = p->link;
    }
    
    prev->link = px;
}


struct node *findCycle(struct node *start)
{
    struct node *slowP, *fastP;
    
    if(start->link == NULL) // only one element in the list
        return NULL;
    
    slowP = fastP = start;
    
    
    while( (fastP != NULL) && (fastP->link != NULL)) {
        slowP = slowP->link;
        fastP = fastP->link->link;
        if(slowP == fastP)
            return slowP;
    }
    
    return NULL;
}

void removeCycle(struct node *start, struct node *pC)
{
    int lenCycle, lenRem, lengthlist, i;
    
    struct node *p, *q;
    
    p = q = pC;
    
    lenCycle = 0;
    
    do {
        lenCycle++;
        q = q->link;
    }while(p != q);
    
    printf("\np = q : %d\n", p->info);
    p = start;
    lenRem = 0;
    
    while(p != q) {
        lenRem++;
        p = p->link;
        q = q->link;
    }
    printf("\np = q : %d\n", p->info);    
    lengthlist = lenCycle + lenRem;
    printf("\nlenCycle : %d\nlenRem : %d\nlengthlist : %d",lenCycle, lenRem,lengthlist);
    p = start;
    
    for(i=1; i<=lengthlist-1; i++)
        p= p->link;
    
    p->link = NULL;
}

int main() {
    struct node *list=NULL;
    struct node *temp;
    int x;
    
    list = create_list(list);
    displayList(list);
    
    x = 40;
    
    insertCycle(list, x);
    temp = findCycle(list);
    printf("\nCycle in the node : %d\n",temp->info);
    removeCycle(list,temp);
    displayList(list);
    return 0;
}