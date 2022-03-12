#include <stdio.h>

int main(){
    long long int result = 0;
    int count;
    int countSix = 0;
    int temp;
    scanf("%d",&count);
    while(count > 0){
        countSix = 0;
        result++;
        temp = result;
        while(temp > 0){
            if(countSix >= 3) break;
            if(temp % 10 == 6)
                countSix++;
            else
                countSix = 0;
            temp /= 10;

        }
        if(countSix > 2){
            count--;
            
        }
    }
    printf("%d\n",result);
}