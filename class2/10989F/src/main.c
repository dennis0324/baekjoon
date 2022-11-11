// 수 정렬하기3
#include <stdio.h>
#include <stdlib.h>


int n,c,a;
int arr[10001];


int main(){
    scanf("%d",&n);
    for(int i = 0 ; i < n; i++){
        scanf("%d",&a);
        arr[a]++;
    }
    for(int i = 1; i <= 10000; i++){
        for(int j = 0; j < arr[i]; j++){
            printf("%d \n",i);
        }
    }
    return 0;
}