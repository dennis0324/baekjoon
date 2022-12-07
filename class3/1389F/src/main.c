#include <stdio.h>

dist[100][100],n,m,min = 5000,index,a,b;
int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0; i<n;i++)
        for(int j = 0; j<n;j++)
            if(j != i)
                dist[i][j] = 500;
    for(int i = 0; i < m; i++){
        scanf("%d %d",&a,&b);
        dist[a - 1][b - 1] = 1;
        dist[b - 1][a - 1] = 1;
    }

    for(int i = 0; i < n; i++)
        for(int x = 0; x < n; x++)
            for(int y = 0; y <n; y++)
                if(dist[x][y] > dist[x][i] + dist[i][y])
                    dist[x][y] = dist[x][i] + dist[i][y];
    
    for(int x =0 ; x <n;x++){
        int sum =0;
        for(int y = 0; y <n; y++)
            if(dist[x][y] != 500)
                sum += dist[x][y];
        if(min > sum){
            index = x;
            min = sum;
        }
    }

    printf("%d\n",index + 1);
    return 0;
}