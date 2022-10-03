#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include <stdio.h>
#include <stdlib.h>

#ifndef ARRAY_QUEUE_ITEM
#define ARRAY_QUEUE_ITEM int
#endif


#define ARRAY_DS_MAX_SIZE 100


typedef struct Queue_Array{
    int front;
    int rear;
    ARRAY_QUEUE_ITEM data[ARRAY_DS_MAX_SIZE];
}QueueArray;

int is_full_AQueue(QueueArray * queue){
    return (queue->rear + 1 % ARRAY_DS_MAX_SIZE ) == queue->front;
}

int is_empty_AQueue(QueueArray * queue){
    return queue->front == queue->rear;
}

QueueArray * create_AQueue(){
    QueueArray * result = (QueueArray *)malloc(sizeof(QueueArray));
    result->rear = 0;
    result->front = 0;
    return result;
}
void enque(QueueArray * queue,ARRAY_QUEUE_ITEM data){
    if(is_full_AQueue(queue)){
        printf("큐가 비었습니다.");
        return ;
    }
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear+1)%ARRAY_DS_MAX_SIZE;
}

ARRAY_QUEUE_ITEM deque(QueueArray * queue){
    ARRAY_QUEUE_ITEM data = queue->data[queue->front];
    queue->front = (queue->front+1)%ARRAY_DS_MAX_SIZE;
    return data;
}




#endif