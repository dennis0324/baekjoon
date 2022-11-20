#include <stdio.h>

int n,nn;
int dp[1000002];//1000002
int vis[1000002];
int main(){
    scanf("%d",&n);
    for(int i = 2 ; i <= n; i++){
        dp[i] = dp[i - 1] + 1;
        vis[i] = i - 1;
        if(!(i%3)){
            if(dp[i] >= dp[i/3] + 1){
                dp[i] = dp[i/3] + 1;
                vis[i] = i /3;
            }
        }

        if(!(i%2)){
            if(dp[i] >= dp[i/2] + 1){
                dp[i] = dp[i/2] + 1;
                vis[i] = i /2;
            }
        }
    }

    printf("%d\n",dp[n]);
    int v = n;
    while(v != 0){
        printf("%d ",v);
        v = vis[v];
    }
    return 0;
}
