#include <stdio.h>
#include <math.h>

int a,b,n;
long long count,dest;
recur(int xCord,int yCord, int size){//x,y
    int halfX = xCord - size;
    int halfY = yCord - size;
    if(size == 0) {
        if(b == xCord && a == yCord) dest = count;
        count++;
        return;
    };
    if(halfX >= b && halfY >= a)
        recur(halfX,halfY,size /2);
    else count += size * size;
    if(halfX < b && halfY >= a)
        recur(xCord,halfY,size/ 2);
    else count += size * size;
    if(halfX >= b && halfY < a)
        recur(halfX,yCord,size / 2);
    else count += size * size;
    if(halfX < b && halfY < a)
        recur(xCord,yCord,size / 2);
    else count += size * size;
}

int main(){
    scanf("%d %d %d",&n,&a,&b);
    int size = (int)pow(2,n);
    recur(size - 1,size - 1,size / 2);
    
    printf("%d\n",dest);
    return 0;
}