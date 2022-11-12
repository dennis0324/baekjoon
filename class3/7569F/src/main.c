#include <stdio.h>
int arr[101][101][101];
int vis[101][101][101];

typedef struct{
    int x;
    int y;
    int z;
}P;

P direction[] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
P que[1000003];
int front,rear,m,n,h,temp,max,able = 1;
void bfs(){
    for(int z = 0; z < h; z++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[z][i][j] == 1 && !vis[z][i][j]){
                    que[rear++] = (P){i,j,z};
                    vis[z][i][j] = 1;
                }
            }
        }
    }

    
    P temp;
    while(front != rear){
        temp = que[front++];
        for(int i =0 ; i < 6 ;i++){
            int offsetX = temp.x + direction[i].x;
            int offsetY = temp.y + direction[i].y;
            int offsetZ = temp.z + direction[i].z;
            if(offsetX < 0 || offsetX >= n || offsetY < 0 || offsetY >= m|| offsetZ < 0 || offsetZ >= h) continue;
            if(!vis[offsetZ][offsetX][offsetY]){
                que[rear++] = (P){offsetX,offsetY,offsetZ};
                vis[offsetZ][offsetX][offsetY] = vis[temp.z][temp.x][temp.y] + 1;
            }
        }

    }
}

int main(){
    scanf("%d %d %d",&m,&n,&h);
    for(int z = 0; z < h; z++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d",&temp);
                if(temp == -1) vis[z][i][j] = -1;
                arr[z][i][j] = temp;
            }
        }
    }
    bfs();
    for(int z = 0; z < h; z++){
        for(int i = 0 ; i < n; i++){
            for(int j =0;j < m;j++){
                if(vis[z][i][j] == 0){
                    able = 0;
                    break;
                }
                if(max < vis[z][i][j])
                    max =vis[z][i][j];
            }
        }
    }

    printf("%d",able ? max - 1 : -1);
    return 0;
}