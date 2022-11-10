#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 1000001

int main(){
    bool arr[MAX_SIZE] = {0};
    long long int min, max,temp, startat,i = 2,count = 0;

    scanf("%lld %lld",&min,&max);
    count = max - min + 1;
    while(i * i <= max){
        temp = min / (i * i);
        if(min % (i * i) != 0){
            temp++;
        }
        while(i * i * temp <= max){
            if(arr[(i * i) * temp - min] == false){
                arr[(i * i) * temp - min] = true;
                count--;
            }
            temp++;
        }
        i++;
    }
    printf("%lld",count);
    return 0;
}