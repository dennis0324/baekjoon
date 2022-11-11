#include <stdio.h>
#include <stdlib.h>

typedef struct total{
    int count;
    int key;
}total;

int curIndex;
total b[500001] = {0};

int compare(const void * A, const void * B){
    int * a = (int *)A; int * b = (int *)B;
    return (*a > *b) - ( *a < *b);
}

int bin_searh(int search){
    int start = 0;
    int end = curIndex - 1;
    while(start <= end){
        int temp = (start + end) / 2;
        if(b[temp].key == search) {
            return b[temp].count;
        }
        else if(b[temp].key > search) end = temp -1;
        else if(b[temp].key < search) start = temp + 1;

    }
    return 0;
}
int main(){
    int search,count,a[500001] = {0},pre = 0;

    scanf("%d",&count);
    for(int i =0 ; i < count ; i++){
        scanf("%d",&a[i]);
    }
    qsort(a,count,4,compare);
    
    total t = {
        .count = 0,
        .key = 0
    };
    for(int i = 0; i <= count; i++){
        if(a[pre] != a[i]){
            t.key = a[pre];
            b[curIndex++] = t;
            pre = i;
            t.count = 1;
        }
        else{
            t.count++;
        }
    }

    scanf("%d",&count);

    for(int i =0 ; i < count; i++){
        scanf("%d",&search);
        printf("%d\n",bin_searh(search));
    }
}