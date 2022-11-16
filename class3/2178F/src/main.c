#include <stdio.h>

typedef struct P{int x;int y;}P;
int n,m,size,temp,vis[100][100];
P q[100001];
P direct[] = {{1,0},{-1,0},{0,1},{0,-1}};

void enq(int i,int j,int count){q[size++] = (P){i,j};vis[i][j] = count;}

int main(){
    int f = 0;
    int j;
    scanf("%d %d",&n,&m); // 세로 가로
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            scanf("%1d",&temp); 
            if(!temp) vis[i][j] = -1;
        }

    enq(0,0,1);
    vis[0][0] = 1;
    while(f != size){
        P t = q[f++];
        for(int i = 0; i < 4;i ++){
            int oX = t.x + direct[i].x;
            int oY = t.y + direct[i].y; 
            if(oX < 0 || oX >= n || oY < 0 || oY >= m) continue;;
            if(!vis[oX][oY])
                enq(oX,oY,vis[t.x][t.y] + 1);
        }
    }
    printf("%d\n",vis[n - 1][m - 1]);
}