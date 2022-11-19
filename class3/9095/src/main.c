#include <stdio.h>

int dp[11]; 
int t;
int main(){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int n; 
    for(int i = 4 ; i <= 10; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    

}