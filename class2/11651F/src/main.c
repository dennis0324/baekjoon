// 좌표 정렬하기 2

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
}P;

int n,x,y;
P arr[100000];
int compare(const void * A, const void * B){
    P * a = (P *)A; P * b = (P*)B;
    if(a->y != b->y) return (a->y > b->y) - (a->y < b->y);
    else return ( a->x > b->x) - (a->x < b->x);
}
int main(){
    scanf("%d",&n);
    P p;
    for(int i = 0; i < n; i++){
        scanf("%d %d",&p.x,&p.y);
        arr[i] = p;
    }

    qsort(arr,n,sizeof(P),compare);

    for(int i = 0; i < n; i++){
        printf("%d %d\n",arr[i].x ,arr[i].y);
    }

    return 0;
}