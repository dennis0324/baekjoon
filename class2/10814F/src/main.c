#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[101];
    int age;
    int order;
}person;


int compare(const void * A,const void *B){
    person * a = (person *)A; person * b = (person *)B;
    int c = (a->age > b->age) - (a->age < b->age);
    if(c == 0)
        return (a->order > b->order) - (a->order < b->order);
    return c;
    
} 

int main(){
    int count;
    scanf("%d",&count);
    person arr[count];
    for(int i = 0; i < count; i++){
        scanf("%d %s",&arr[i].age,arr[i].name);
        arr[i].order = i;
    }
    qsort(arr,count,sizeof(person),compare);

    for(int i = 0 ; i < count;i++){
        printf("%d %s\n",arr[i].age,arr[i].name);
    }
}