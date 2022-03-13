#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD

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
=======
typedef struct data
{
    int weight;
    int height;
    int rank;
}DATA;
>>>>>>> a463db4c56eec7111d928af6bceadb2bde7245ce

int main(){
    DATA people[50];
    int count;
<<<<<<< HEAD
    scanf("%d",&count);
    for(int i =0; i < count; i++){
        scanf("%d %d",&people[i].weight,&people[i].height);
        people[i].id = 0;
    }
    qsort(people,count,sizeof(DATA),compare);


    printf("");
=======
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
>>>>>>> a463db4c56eec7111d928af6bceadb2bde7245ce
}