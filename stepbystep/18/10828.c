#include <stdio.h>
typedef struct array{
    int count;
    int data[10000];
}ARRAY;

void push(ARRAY * arr){
    int x;
    scanf("%d",&x);
    (*arr).data[++(*arr).count] = x;
}

int pop(ARRAY * arr){
    if((*arr).count < 0)
        return -1;
    return (*arr).data[(*arr).count--];
}

int size(ARRAY * arr){
    return (*arr).count + 1;
}

int empty(ARRAY * arr){
    if((*arr).count < 0) return 1;
    else return 0;
}

int top(ARRAY * arr){
    if((*arr).count < 0) return -1;
    return (*arr).data[(*arr).count];
}

int stringCompare(char * a, char * b){
    int i = 0;
    while(a[i] != NULL){
        if(a[i] != b[i]) return 0;
        i++;
    }
    return 1;

}
int main(){
    ARRAY stack;
    char cmd[50];
    int value;
    int repeatCount;
    int result;
    stack.count = -1;
    scanf("%d",&repeatCount);
    for(int i = 0; i < repeatCount; i++){
        scanf("%s",&cmd);
        if(stringCompare(cmd,"push")){
            push(&stack);
        }
        else if(stringCompare(cmd,"pop")){
            result = pop(&stack);
            printf("%d\n",result);
        }
        else if(stringCompare(cmd,"size")){
            result = size(&stack);
            printf("%d\n",result);

        }
        else if(stringCompare(cmd,"empty")){
            result = empty(&stack);
            printf("%d\n",result);

        }
        else if(stringCompare(cmd,"top")){
            result = top(&stack);
            printf("%d\n",result);

        }
    }



}