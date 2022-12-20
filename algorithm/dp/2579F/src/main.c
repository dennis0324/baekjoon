#include <stdio.h>

stairs[301];
dp[301];
total;
index;
N;
int main(){
    scanf("%d",&N);
    for(int i = 1;i <= N; i++){
        scanf(" %d",stairs + i);
    }
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = stairs[1] + stairs[3] > stairs[2] + stairs[3] ? stairs[1] + stairs[3] : stairs[2] + stairs[3];

    for(int i = 4; i <= N; i++){
        dp[i] = dp[i - 2] + stairs[i] > dp[i - 3] + stairs[i - 1] + stairs[i] ? dp[i - 2] + stairs[i] : dp[i - 3] + stairs[i - 1] + stairs[i];
    }

    printf("%d",dp[N]);
    return 0;
}

// 0 1 2 3 4 5 