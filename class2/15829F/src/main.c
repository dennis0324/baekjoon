#include <string.h>
#include <stdio.h>

#define M 1234567891
int l;
long long sum;
int main(){
    scanf("%d%*c",&l);
    long long mul = 1;
    for(int i = 0; i < l; i++){
        long long charIndex = (getc(stdin) - 'a' + 1);
        sum += (charIndex * mul) % M;
        mul *= 31;
        mul %= M;
    }
    printf("%lld\n",sum % M);
    return 0;
}
