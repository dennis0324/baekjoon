#include <stdio.h>

int main(){
    long long a,b;
    int count = 0;
    long long total;
    long long i = 1;
    long long totalCount = 0;
    long long temp;
    scanf("%lld %lld",&a,&b);
    total = b - a + 1;
    while(a <= b){
        i = 1;
        // printf("%lld\n",a);
        while(i *i  <= a){
            if(i == 1) {
                i++;
                continue;
            }
            if(a % (i * i) == 0){
                count++;
                break;
            }
            i++;
        }
        a++;

    }
    printf("%lld",total - count);
}