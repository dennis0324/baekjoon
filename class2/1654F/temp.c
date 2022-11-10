#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void * A, const void * B){
    int * a = (int *)A; int * b = (int *)B;
    return (*a < *b) - (*a > *b);
}

int bin_search(int * wire,int total,int c,int d){
    long long start = 1;
    qsort(wire,c,4,compare);
    long long end = wire[0];
    while(start <= end){
        long long temp = (start + end) / 2;
        long long wire_count = 0;
        for(int j = 0; j < c; j++){
            wire_count += wire[j] / temp;
        }
        if(d > wire_count) end = temp - 1;
        else {
            start = temp + 1;
        }
    }

    return end;

}

int main(){
    int wire[10001] = {0};
    int c, d,t;
    int total = 0;
    scanf("%d %d",&c,&d);

    for(int i = 0; i < c;i++){
        scanf("%d",&wire[i]);
        total += wire[i];
    }

    int result = bin_search(wire,total,c,d);
    printf("%d",result);
    return 0;
}