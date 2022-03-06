#include <stdio.h>
int fabo(int input){
    if(input == 1) return 1;
    if(input == 0) return 0;
    return fabo(input - 1) + fabo(input - 2);
}

int main(){
    int a = 0;
    int b = 1;
    int input;
    scanf("%d",&input);
    int result =fabo(input);
    printf("%d",result);
    
    return 0;
}