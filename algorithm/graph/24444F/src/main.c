#include <stdio.h>
#include <stdlib.h>

int n,m,r;
int a,b; //간선을 읽기 위한 임시 변수
int * data[200002];
int length[200002]; // 200001

int que[200002];// 200001
int front,rear;

int vis[100002];

int num = 1; 
int compare(const void * A, const void * B){
    int * a = (int *)A; int * b = (int *)B;
    return (*a < *b) - (*a > *b);
}
void bfs(int s){
    for(int i = 1 ; i <= n; i++){
        qsort(data[i],length[i],4,compare);
    }
    vis[s] = num++;
    rear = (rear + 1) % 200002;
    que[rear] = s;
    while(front != rear){
        front = (front + 1) % 200002;
        int v = que[front];
        for(int i = 0; i < length[v]; i++){
            if(!vis[data[v][i]]){
                rear = (rear + 1) % 200002;
                que[rear] = data[v][i];
                vis[data[v][i]] = num++;
            }
        }
    }
}


int main(){
    scanf("%d %d %d",&n,&m,&r);
    for(int i = 0; i < m; i++){
        scanf("%d %d",&a,&b);
        data[a] = realloc(data[a],4*length[a]+4);
        data[b] = realloc(data[b],4*length[b]+4);
        data[a][length[a]++] = b;
        data[b][length[b]++] = a;
    }

    bfs(r);

    for(int i = 1; i <= n; i++){
        printf("%d\n",vis[i]);
    }
    return 0;
}