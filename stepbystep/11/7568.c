#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int weight;
    int height;
    int rank;
}DATA;

int main(){
    DATA people[50];
    int count;
    int tempRank;
    scanf("%d",&count);
    for(int i = 0; i < count; i++){
        scanf("%d %d",&people[i].weight,&people[i].height);
        people[i].rank = 0;
    }
        
    for(int i = 0; i < count; i++){
        for(int j = 0; j < count; j++){
            if(people[i].height > people[j].height && people[i].weight > people[j].weight) people[j].rank++;
            else if(people[i].height < people[i].height && people[i].weight < people[i].weight) people[i].rank++;
        }
    }

    for(int i = 0; i < count; i++){
        printf("%d ",people[i].rank + 1);
    }
}