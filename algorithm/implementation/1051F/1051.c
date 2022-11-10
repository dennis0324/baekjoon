#include <stdio.h>
#include <math.h>

typedef struct squareData{
    int length;
    int startpoint;
    
};
int main(){
    int n,m;
    int data[50][50];
    int i,j;
    int length;
    int result = 1;
    scanf("%d %d",&n,&m);
    for(i = 0;i< n;i++ ){
        for(j =0;j <m;j++){
            scanf("%1d",&data[j][i]);
        }
    }
    if(m > n) length = n;
    else length = m;

    while(length > 1){
        for(i = 0;i + length<=n;i++){
            for(j = 0;j+ length<=m;j++){
                int temp = data[j][i];
                if(data[j+length - 1][i+length - 1] != temp) continue;
                if(data[j+length - 1][i] != temp) continue;
                if(data[j][i+length - 1] != temp) continue;
            
                result = length * length;
                break;
            }
            if(result != 1) break;
        }
        if(result != 1) break;
        length--;
    }

    printf("%d",result);

}