#ifndef ARRAY_DATASTRUCT_H
#define ARRAY_DATASTRUCT_H


#ifndef ARRAY_STACK_ITEM
#define ARRAY_STACK_ITEM int
#endif

#define ARRAY_DS_MAX_SIZE 100

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
    stack->top == -1;
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

int is_full_AStack(StackArray * stack){
    return stack->top == ARRAY_DS_MAX_SIZE;
}

int is_empty_AStack(StackArray * stack){
    return stack->top == -1;
}

#endif