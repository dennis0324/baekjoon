#include <stdio.h>
#include <stdlib.h>

int n,m;
int show[9];

int compare(const void * A, const void * B){
    int * a = (int *)A; int * b = (int *)B;
    return (*a > *b) - (*a < *b);
}

void dfs(int * arr1,int * arr2,int s,int c,int t){
    arr2[c] = s;
    if(c == m){
        for(int j = 1; j < m; j++){
            if(arr2[j] > arr2[j+1])
                return;
        }
        for(int j = 1; j <= m; j++)
            printf("%d ",show[arr2[j]]);
        printf("\n");
        return;
    }

    for(int i = t; i < n; i++){
        arr1[i] = 1;
        dfs(arr1,arr2,i,c+1,t);
        arr1[i] = 0;
    }

}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++){
        scanf("%d",&show[i]);
    }
    qsort(show,n,4,compare);
    int * vis[9] = {0};
    int * mem[9] = {0};
    for(int i = 0; i < n; i++){
        dfs(vis,mem,i,1,i);
    }
    return 0;
}