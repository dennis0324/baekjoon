#include <stdio.h>
#include <stdlib.h>

int c;
int biggest;
int compare(const void * A, const void * B){
    int * a = (int*)A; int * b = (int*)B;
    return (*a > *b) - (*a < *b);
}
int main(){
    int arr[1000000];
    scanf("%d",&c);
    for(int i = 0 ; i< c; i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,c,sizeof(int),compare);

    for(int i = 0; i < c; i++){
        printf("%d\n",arr[i]);
    }
}