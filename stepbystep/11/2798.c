#include <stdio.h>

int main(){
    int targetNum;
    int cardCount;
    int card[100];
    int sum,biggest = 0;
    scanf("%d %d",&cardCount, &targetNum);
    for(int i = 0; i < cardCount; i++)
        scanf("%d",&card[i]);

    for(int i = 0; i < cardCount - 2; i++){
        for(int j = i + 1; j < cardCount - 1;j++){
            for(int z = j + 1;z < cardCount; z++){
                sum = card[i] + card[j] + card[z];
                if(targetNum >= sum){
                    if(biggest < sum){
                        biggest = sum;
                    }
                }
            }
        }
    }
    printf("%d",biggest);
    return 0;
}