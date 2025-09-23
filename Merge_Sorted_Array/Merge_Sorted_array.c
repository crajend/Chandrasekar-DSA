// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

void display(int arr[], int n) {
    
    int i;
    
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
    
    printf("\n");
}

int main() {
    int a[] = {9,11,15,31,39,43,100}, b[] = {2,10,17,29,40,45,67,79};
    int la = sizeof(a)/sizeof(a[0]),lb = sizeof(b)/sizeof(b[0]),lm;
    int i=0,j=0,k=0;
    int m[la + lb];
    
    lm = la+lb;
    printf("la = %d lb = %d lm = %d\n",la,lb,lm);
    
    display(a, la);
    display(b, lb);
    
    while( ( i < la ) && ( j < lb )) {
        if(a[i] < b[j]) 
            m[k++] = a[i++];
        else 
            m[k++] = b[j++];
    }
    
    
    while(i < la)
        m[k++] = a[i++];
    
    while(j < lb)
        m[k++] = b[j++];
    
    display(m, lm);
    return 0;
}