#include <stdio.h>
#include <string.h>

#define QUEUEELEMENT int

typedef struct queue_type{
    int front;
    int rear;
    int total;
    QUEUEELEMENT * data;
}QueueType;


QueueType * create_queue(int n){
    QueueType * result = (QueueType *)malloc(sizeof(QueueType));
    result->data = (QUEUEELEMENT *)malloc(sizeof(QUEUEELEMENT) * n);
    result->total = n;
    result->front = 0;
    result->rear = 0;
    return result;
}

void destroy_queue(QueueType * q){
    free(q->data);
    free(q);
}

int queue_is_full(QueueType * queue){
    return (queue->rear + 1 % queue->total ) == queue->front;
}

int queue_is_empty(QueueType * queue){
    return queue->front == queue->rear;
}

QueueType * create_AQueue(){
    QueueType * result = (QueueType *)malloc(sizeof(QueueType));
    result->rear = 0;
    result->front = 0;
    return result;
}
int queue_enque(QueueType * queue,QUEUEELEMENT data){
    if(queue_is_full(queue)){
        return 0;
    }
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear+1)%queue->total;
    return 1;
}

int queue_deque(QueueType * queue,QUEUEELEMENT * resultValue){
    if(queue_is_empty(queue)) return 0;
    if(resultValue != NULL)
        *resultValue = queue->data[queue->front];
    queue->front = (queue->front+1)%queue->total;
    return 1;
}


int main(){
    int command;
    scanf("%d",&command);
    char input[10];
    QueueType * q = create_queue(command + 1);
    
    while(command--){
        scanf("%s",input);
        if(!strcmp(input,"push")){
            int temp;
            scanf("%d",&temp);
            queue_enque(q,temp);
        }
        else if(!strcmp(input,"pop")){
            int temp;
            if(!queue_deque(q,&temp)){
                temp = -1;
            }
            printf("%d\n",temp);
        }
        else if(!strcmp(input,"size")){
            printf("%d\n",(q->rear - q->front + q->total) % q->total);
        }
        else if(!strcmp(input,"empty")){
            printf("%d\n",queue_is_empty(q));
        }
        else if(!strcmp(input,"front")){
            if(queue_is_empty(q)) printf("-1\n");
            else printf("%d\n",q->data[q->front]);
        }
        else if(!strcmp(input,"back")){
            if(queue_is_empty(q)) printf("-1\n");
            else printf("%d\n",q->data[q->rear - 1]);
        }
    }

    destroy_queue(q);
}