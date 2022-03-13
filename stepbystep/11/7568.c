#include <stdio.h>
#include <stdlib.h>


typedef struct data
{
    int height;
    int weight;
    int id;
}DATA;
int static compare(DATA* first, DATA* second){
    if((*first).height > (*second).height && (*first).weight > (*second).weight) return 1;
    else if((*first).height < (*second).height && (*first).weight < (*second).weight) return -1;
    else return 0;
}

int main(){
    DATA people[50];
    int count;
    scanf("%d",&count);
    for(int i =0; i < count; i++){
        scanf("%d %d",&people[i].weight,&people[i].height);
        people[i].id = 0;
    }
    qsort(people,count,sizeof(DATA),compare);


    printf("");
}