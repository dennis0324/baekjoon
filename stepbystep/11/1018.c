#include <stdio.h>

int main(){
    int n, m;
    char wood[50][50];
    char color[2] = {'B','W'};
    int count = 0;
    int editCount = 0;
    int smallest = 2500;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++){
        while( getchar() != '\n' );
        for(int j = 0;j < m; j++){
            scanf("%c",&wood[i][j]);
        }
        
    }

    for(int i = 0; i < n - 7; i++){
        for(int j = 0; j < m - 7; j++){
            for(int start = 0; start < 2; start++){
                editCount = 0;
                count = start;
                for(int height = 0; height < 8; height++){
                    for(int width = 0; width < 8; width++){
                        if(wood[i + height][j + width] != color[count]) editCount++;
                        count = !count;
                    }
                    count = !count;
                }
                if(smallest > editCount) smallest = editCount;
            }
        }
    }
    printf("%d",smallest);
    return 0;
} 