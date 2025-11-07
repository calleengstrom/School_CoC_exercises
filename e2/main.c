#include <stdio.h>
#include <stdlib.h>

void main(){
    int n =10;
    int size = n + sizeof(int);
    int size2 = sizeof(int) + (sizeof(int)/10);
    int size3 = n + ((sizeof(int)*n)/10);


    printf("N = %d\n Size 1 = %d \n Size 2  = %d\n Size 3 = %d ",n,size,size2,size3);
}