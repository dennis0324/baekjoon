// 달팽이는 올라가고 싶다

#include <stdio.h>

int a,b,v;
int count;
int main(){
    scanf("%d %d %d",&a,&b,&v);
    v -= a;
    count = v / (a-b);
    int temp  = v % (a-b);
    if(temp != 0) count++;
    printf("%d",count + 1);
    return 0;
}