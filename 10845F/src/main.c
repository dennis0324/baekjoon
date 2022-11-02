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
    queue->rear = (queue->rear+1)%queue->total;
    queue->data[queue->rear] = data;
    return 1;
}

int queue_deque(QueueType * queue,QUEUEELEMENT * resultValue){
    if(queue_is_empty(queue)) return 0;
    queue->front = (queue->front+1)%queue->total;
    if(resultValue != NULL)
        *resultValue = queue->data[queue->front];
    return 1;
}

int queue_enque_front(QueueType * queue,QUEUEELEMENT data){
    if(queue_is_full(queue_is_full)){
        return 0;
    }
    queue->data[queue->front] = data;
    queue->front = (queue->front - 1 + queue->total) % queue->total;
    return 1;
}

int queue_deque_back(QueueType * queue,QUEUEELEMENT * resultValue){
    if(resultValue != NULL)
        *resultValue = queue->data[queue->rear];
    if(queue_is_empty(queue)) return 0;
    queue->rear = (queue->rear - 1 + queue->total) % queue->total;
    return 1;
}


int main(){
    int command;
    scanf("%d",&command);
    char input[20];
    QueueType * q = create_queue(command + 2);
    
    while(command--){
        scanf("%s",input);
        if(!strcmp(input,"push_front")){
            int temp;
            scanf("%d",&temp);
            queue_enque_front(q,temp);
        }
        if(!strcmp(input,"push_back")){
            int temp;
            scanf("%d",&temp);
            queue_enque(q,temp);
        }
        else if(!strcmp(input,"pop_front")){
            int temp;
            if(!queue_deque(q,&temp)){
                temp = -1;
            }
            printf("%d\n",temp);
        }
        else if(!strcmp(input,"pop_back")){
            int temp;
            if(!queue_deque_back(q,&temp)){
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
            else printf("%d\n",q->data[(q->front + 1) % q->total]);
        }
        else if(!strcmp(input,"back")){
            if(queue_is_empty(q)) printf("-1\n");
            else printf("%d\n",q->data[q->rear]);
        }
    }

    destroy_queue(q);
}