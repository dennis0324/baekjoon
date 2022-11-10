#include <stdio.h>

int a,b,c,r,i,vis[1000];
int main(){
    scanf("%d %d",&a,&b);
    printf("<");
    c = a;
    while(c){
        if(!vis[i]) r++;
        if(r != 0 && r % b == 0){
            vis[i] = 1;
            r=0;
            printf("%d",i + 1);
            if(c != 1) printf(", ");
            c--;
        }
        i = (i + 1) % a;
    }
    printf(">");
    return 0;
}