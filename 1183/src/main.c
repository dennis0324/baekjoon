#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    int n,a,b,y[10000];
    scanf("%d",&n);
    for(int i = 0 ;i < n; i++){
        scanf("%d %d", &a, &b);
        y[i] = a - b;
    }
    qsort(y,n,sizeof(int),cmp);
    if (n % 2) printf("1\n");
    else printf("%d\n", abs(y[n / 2] - y[n / 2 - 1]) + 1);
}