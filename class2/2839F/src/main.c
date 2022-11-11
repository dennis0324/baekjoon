#include <stdio.h>

int n;
int min = 5000,able,temp,count;

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n / 5 + 1; i++){
        int five = n - count * 5;
        if(five % 3== 0){
            temp = five / 3;
            if(min > count + temp){
                min = count + temp;
                able = 1;    
            }
        }
        count++;
    }
    printf("%d",!able ? -1 : min);
    return 0;
}
