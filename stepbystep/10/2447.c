#include <stdio.h>
int star(int i, int j,int n){
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1){
        printf(" ");
    }
    else{
        if( n / 3 == 0){
            printf("*");
        }
        else{
            star(i,j,n/3);
        }
    }
}
int main(){
    int printStarCount;

    scanf("%d",&printStarCount);
    for(int i = 0;i < printStarCount; i++){
        for(int j = 0;j <printStarCount; j++){
            star(i,j,printStarCount);
        }
        printf("\n");
    }
    return 0;
}