#include <stdlib.h>

arr[1001];
d[1001];
c,index,t = 1;


int compare(const void * A, const void *B){
    int * a= (int *)A;
    int * b= (int *)B;
    return (*a < *b) - (*a > *b);
}
int main(){
    d[0] = 0;
    scanf("%d",&c);
    for(int i = 1 ; i <= c;i++){
        scanf("%d",&arr[i]);
    }

    for(int i = 1; i <= c;i++){
        int big = 0;
        for(int j = 0; j < i; j++)
            if(d[big] < d[j] && arr[j] < arr[i])
                big = j;
        d[i] = d[big] + 1;
    }
    qsort(d,1001,4,compare);
    printf("%d",d[0]);
}