#include <stdio.h>
#define MAX_SIZE 100000

int main(){
    char arr[MAX_SIZE * 2] = {0};
    int stack[MAX_SIZE] = {0};
    int current_num = 1,next_num, total,top = -1 ,size = 0;
    int success = 1;
    scanf("%d",&total);
    for(int i = 0; i < total; i++){
        scanf("%d",&next_num);
        // currentNUM <= nextNum -> 푸쉬
        // nextNUM > currentNUM 
        while(1){
            if(current_num <= next_num){
                stack[++top] = current_num;
                arr[size++] = '+';
                current_num++;
            }
            else{
                if(stack[top] > next_num){
                    success = 0;
                    break;
                }
                int temp = stack[top--];
                if(top == -2){
                    break;
                }
                arr[size++] = '-';
                if(temp == next_num) {
                    break;
                }
            }
        }
    }

    if(!success){
        printf("NO");
        return 0;
    }
    for(int i = 0; i < size; i++){
        printf("%c\n",arr[i]);
    }
}