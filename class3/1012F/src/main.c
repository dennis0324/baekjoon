#include <stdio.h>


int w,h,e;
int count = 0;
void dfs(int x,int y,int mat[][50],int visited[][50]){
    if(x < 0 || x >= w || y < 0 || y >= h) return;
    if(visited[x][y] || !mat[x][y]) return;
    visited[x][y] = 1;
    dfs(x - 1,y,mat,visited);
    dfs(x + 1,y,mat,visited);
    dfs(x,y - 1,mat,visited);
    dfs(x,y + 1,mat,visited);
}

int main(){
    int loop;
    scanf("%d",&loop);
    while(loop--){
        int mat[50][50] = {0};
        int visited[50][50] = {0};

        count = 0;
        scanf("%d %d %d",&w,&h,&e);
        for(int i = 0; i < e;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            mat[x][y] = 1;
        }

        for(int i =0 ;i < w; i++){
            for(int j = 0; j < h; j++){
                if(!visited[i][j] && mat[i][j]){
                    dfs(i,j,mat,visited);
                    count++;
                }
            }
        }
        
        printf("%d\n",count);
    }
}


