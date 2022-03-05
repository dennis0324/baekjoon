#include <stdio.h>
#include <math.h>

typedef struct coord{
    int x;
    int y;
}COORD;

typedef struct circle{
    int x;
    int y;
    int rad;
}CIRCLE;

int getCircle(COORD cord,CIRCLE cir){
    int returnValue;
    int circleCal = (cord.x - cir.x) * (cord.x - cir.x) + (cord.y -cir.y) * (cord.y -cir.y);
    int circlePow = cir.rad * cir.rad;
    if(circleCal < circlePow) return 1;
    else if(circleCal > circlePow) return 0;
    else return -1;
    return 0;
}
int main(){
    COORD start, end;
    CIRCLE cir;
    int repeatCount,getCount;
    int i , j;
    int startResult, endResult;
    int result;
    scanf("%d",&repeatCount);
    for(i = 0; i< repeatCount; i++){
        result = 0;
        scanf("%d %d %d %d",&start.x,&start.y,&end.x,&end.y);
        scanf("%d",&getCount);
        for(j = 0;j < getCount; j++){
            scanf("%d %d %d",&cir.x,&cir.y,&cir.rad);
            
            startResult = getCircle(start,cir);
            endResult = getCircle(end,cir);
            if(startResult == -1 || endResult == -1) continue;
            if(startResult + endResult == 1) result++;
        }
        printf("%d\n",result);
    }
}