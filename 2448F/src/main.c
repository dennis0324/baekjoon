#include <stdio.h>

char result[5000][10000];
int n;

void printfTri(int height,int width){
    result[height][width] = '*';
    result[height + 1][width - 1] = '*';
    result[height + 1][width + 1] = '*';
    for(int i = 0 ; i < 5; i++){
        result[height + 2][width - 2 + i] = '*';
    }

}

void triangle(int n, int height, int width){
    if(n ==3){
        printfTri(height,width);
        return;
    }

    triangle(n / 2,height,width);
    triangle(n / 2,height + n / 2,width + n/2);
    triangle(n / 2,height + n / 2,width - n/2);
}



int main(){
    scanf("%d",&n);
    for(int i = 0 ; i < 5000;i++)
        for(int j = 0; j < 10000; j++)
            result[i][j] = ' ';
    
    triangle(n,0,n-1);
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < 2 * n - 1; j++){
            printf("%c",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}