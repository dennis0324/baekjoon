#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int testing(int x1,int y1,int r1,int x2,int y2, int r2){
    double ldistance, y, z;
    double distance = sqrt(pow(x1 - x2,2) + pow( y1 - y2,2));
    if (r1 > distance && r1 > r2){
        ldistance = r1;
        y = distance;
        z = r2;
    }
    else if(distance > r1 && distance > r2){
        ldistance = distance;
        y = r1;
        z = r2;
    }
    else{
        ldistance = r2;
        y = r1;
        z = distance;  
    }

    if(distance == 0){
        if(r2 == r1){
            return -1;
        }
        else{
            return 0;
        }
    }
    else if (ldistance  < y + z){
        return 2;
    }
    else if(ldistance > y + z){
        return 0;
    }
    else{
        return 1;
    }
    return 0;
}
int main(){
    int count = 0;
    scanf("%d",&count);
    for(int i = 0; i < count;i++){
        int arr[6] = {0,0,0,0,0,0};
        scanf("%d %d %d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5]);
        int result = testing(arr[0],arr[1],arr[2],arr[3],arr[4],arr[5]);
        printf("%d\n",result);
    }
    return 0;
}

// main(a,b,c,d,e,f){
//     for(gets(&a);~scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);printf("%d ",d|c ? d<a&d>c?2 : d<=a&d>=c:-1))
//     d*=d-=a,d+=e*=e-=b,a*=a=c+f,c*=c-=f;
//     }
