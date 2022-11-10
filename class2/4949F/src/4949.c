

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifndef ARRAY_STACK_ITEM
#define ARRAY_STACK_ITEM int
#endif

#define ARRAY_DS_MAX_SIZE 102

typedef struct Stack_Array{
    int top;
    ARRAY_STACK_ITEM data[ARRAY_DS_MAX_SIZE];
}StackArray;

#include <stdlib.h>
#include <stdio.h>

StackArray * Create_AStack(){
    StackArray * result = (StackArray *)malloc(sizeof(StackArray));
    result->top = -1;

    return result;
}

void clear_AStack(StackArray * stack){
    stack->top = -1;
}

int is_full_AStack(StackArray * stack){
    return stack->top == ARRAY_DS_MAX_SIZE;
}

int is_empty_AStack(StackArray * stack){
    return stack->top == -1;
}
void push_AStack(StackArray* stack,ARRAY_STACK_ITEM value){
    if( is_full_AStack(stack)){
        printf("stack is full");
        return;
    }
    stack->data[++stack->top] = value;
}

ARRAY_STACK_ITEM pop_AStack(StackArray * stack){
    if(is_empty_AStack(stack)){
        printf("stack is empty");
        return NULL;
    }
    return stack->data[--stack->top];
}

ARRAY_STACK_ITEM peek_AStack(StackArray * stack){
    return stack->data[stack->top];
}

bool custom_push(StackArray * s,char c){
    char peekc;
    switch (c)
    {
    case '(':
    case '[':
        push_AStack(s,c);
        break;
    case ')':
    case ']':
        if(is_empty_AStack(s)) return false;
        peekc = peek_AStack(s);
        if(peekc == '['){
            pop_AStack(s);
            return true;
        }
        else if(peekc == '('){
            pop_AStack(s);
            return true;
        }
        else return false;
        break;
    default:
        break;
    }
    return true;
}
int main(){
    StackArray * stack = Create_AStack();
    bool result;

    while(1){
        char arr[102] = {0};
        result = true;
        fgets(arr,102,stdin);
        int i = 0; 
        if(arr[0] == '.' &&arr[1] =='\n') break;
        
        while(!(arr[i] == '.' && arr[i+1] =='\n')){
            if(!custom_push(stack,arr[i]))
                result = false;
            i++;
        }
        if(!is_empty_AStack(stack))
            result = false;

        if(result) printf("yes\n");
        else printf("no\n");
        clear_AStack(stack);
    }

    free(stack);
    return 0;
}