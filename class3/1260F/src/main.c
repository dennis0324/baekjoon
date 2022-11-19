#include <stdio.h>
#include <string.h>

int edge[1000][1000];

int n,m,v; 
int s,e;

int flag[1000];
int count = 1;
int dfs(int s){
    flag[s] = count++;
    printf("%d ",s+1);
    for(int i =0 ; i < n; i++){
        if(edge[s][i] && !flag[i])
            dfs(i);
    }
}

int que[10002];
int front,rear;
int bfs(int s){
    que[rear++] = s;
    flag[s] = count++;
    printf("%d ",s+1);
    while(front != rear){
        int vertex = que[front++];
        for(int i = 0 ; i < n; i++){
            if(edge[vertex][i] && !flag[i]){
                que[rear++] = i;
                printf("%d ",i+1);
                flag[i] = count++;
            }
        }
    }
}

int main(){
    scanf("%d %d %d",&n,&m,&v);
    for(int i = 0; i< m;i++){
        scanf("%d %d",&s,&e);
        edge[s- 1][e - 1] = 1;
        edge[e-1][s-1] = 1;
    }
    dfs(v - 1);
    memset(flag,0,sizeof(4) * 1000);
    printf("\n");
    bfs(v - 1);
}