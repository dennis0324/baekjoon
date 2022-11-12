#include <stdio.h>
int arr[1001][1001];
int vis[1001][1001];

typedef struct{
    int x;
    int y;
}P;

P direction[4] = {{1,0},{-1,0},{0,1},{0,-1}};
P que[1000002];
int front,rear,m,n,temp,max,able = 1;
void bfs(){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1 && !vis[i][j]){
                que[rear++] = (P){i,j};
                vis[i][j] = 1;
            }
        }
    }
    
    P temp;
    while(front != rear){
        temp = que[front++];
        for(int i =0 ; i < 4 ;i++){
            int offsetX = temp.x + direction[i].x;
            int offsetY = temp.y + direction[i].y;
            if(offsetX < 0 || offsetX >= n || offsetY < 0 || offsetY >= m) continue;
            if(!vis[offsetX][offsetY]){
                que[rear++] = (P){offsetX,offsetY};
                vis[offsetX][offsetY] = vis[temp.x][temp.y] + 1;
            }
        }

    }
}



int main(){
    scanf("%d %d",&m,&n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&temp);
            if(temp == -1) vis[i][j] = -1;
            arr[i][j] = temp;
        }
    }
    bfs();
    for(int i = 0 ; i < n; i++){
        for(int j =0;j < m;j++){
            if(vis[i][j] == 0){
                able = 0;
                break;
            }
            if(max < vis[i][j])
                max =vis[i][j];
        }
    }
    printf("%d",able ? max - 1 : -1);
    return 0;
}