#include <stdio.h>

int main(){
    int input, n = 0;
    int stack[100000];
    int num;
    long long total = 0;
    scanf("%d",&input);
    while(input--){
        scanf("%d",&num);
        if(num == 0) stack[--n] = 0;
        else stack[n++] = num;
    }

    while(--n >= 0 ){
        total += stack[n];
    }
    printf("%lld",total);
}