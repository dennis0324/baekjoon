#include <stdio.h>
int factorial(int input){
    int temp = 1;
    if(input > 1)
        temp = factorial(input - 1);
    if(input == 0) return 1;
    return input * temp ;
}
int main(){
    int input;
    scanf("%d",&input);
    int result = factorial(input);
    printf("%d",result);
}