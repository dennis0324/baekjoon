#include <stdio.h>
#include <stdint.h>

int n,m,b;
int data[501][501];
int max_height,min_height = 256,current_height = 256;
int timeSpend = 0;
int min_time = INT32_MAX;
int main(){
    scanf("%d %d %d",&n,&m,&b);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&data[i][j]);
            if(current_height > data[i][j])
                current_height = data[i][j];
        }
    }

    while(1){
        int temp_block = b;
        timeSpend =0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(data[i][j] > current_height){
                    int a = (data[i][j] - current_height);
                    timeSpend += a * 2; 
                    temp_block += a;
                }
                else if(data[i][j] < current_height){
                    int a = (current_height - data[i][j]);
                    timeSpend += a;
                    temp_block -= a;
                }
            }
        }
        if(temp_block < 0) break;
        if(min_time > timeSpend){
            min_time = timeSpend;
            min_height = current_height;
        }
        else if(min_time == timeSpend){
            if(min_height < current_height){
                min_height = current_height;
            }
        }
        current_height++;
    }

    printf("%d %d",min_time,min_height);
    return 0;
}