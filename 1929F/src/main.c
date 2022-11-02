#include <stdio.h>

int arr[1000001];
int a,b;
int main(){
    scanf("%d%d",&a,&b);
    if(a== 1) a++;
    for(int i = 2; i <= b;i++){
        int c = 1;
        while(i * ++c <= 1000000)
            if(arr[i * c] == 0)
                arr[i * c]++;
        
    }

    for(int i = a; i <= b; i++){
        if(arr[i] == 0 ) printf("%d\n",i);
    }
    return 0;
}