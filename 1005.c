#include <stdio.h>
#include <stdlib.h>
typedef struct lineData{
    int count;
    int totalTime;
    int arr[1000];
}lineData;
void push(lineData * data,int next){
    // if((*data).count == 0)
    //     (*data).arr = (int *)malloc(sizeof(int)*(++(*data).count)); //dynatic allocation to store previous building values
    // else
    //     (*data).arr = (int *)realloc((*data).arr,sizeof(int)*(++(*data).count)); //dynatic allocation to store previous building values
    (*data).count++;
    (*data).arr[(*data).count - 1] = next;
}

void freeArr(lineData * arr,int count){
    if(count == 0){
        free((*arr).arr);
    }
    else{
        for( int i = 0; i < count; i++){
            free(arr[i].arr);
        }
    }
}
int main(){
    int i;
    int repeatCount;
    int buildCount,buildRule;
    int before,after;
    scanf("%d",&repeatCount);
    int buildDelay[1001];
    
    int outDegree[1001];
    lineData graph[1001];
    int queue[1000];
    int count = 0;
    lineData result;
    for(int repeat = 0;repeat < repeatCount; repeat++){
        scanf("%d %d",&buildCount,&buildRule);

        for(i =0;i<buildCount;i++){
            int temp;
            scanf("%d",&temp);
            buildDelay[i] = graph[i].totalTime = temp;
            graph[i].count =0;
            outDegree[i] = 0;
        }
            
        for(i =0;i<buildRule;i++){
            scanf("%d %d",&before,&after);
            push(&graph[before - 1],after);
            outDegree[after - 1] += 1;
        }

        while(1){
            count = 0; //0을 받은 횟수이자 큐의 인덱스
            for(i =0; i < buildCount; i++){
                if(outDegree[i] == 0){
                    queue[count] = i + 1;
                    count++;
                    outDegree[i] = -1;
                    push(&result,i + 1);
                }
            }
            if(count == 0) break;

            for(i = 0;i <count;i++){
                for(int j = 0;j < graph[queue[i]- 1].count;j++){
                    int nodeNum = graph[queue[i] - 1].arr[j] - 1; //간선을 표시
                    if(buildDelay[nodeNum] + graph[queue[i] - 1].totalTime > graph[nodeNum].totalTime){
                        graph[nodeNum].totalTime = buildDelay[nodeNum] + graph[queue[i] - 1].totalTime;
                    }
                    outDegree[nodeNum] -= 1;
                }
            }
        }
        int resultIndex;
        scanf("%d",&resultIndex);
        printf("%d\n",graph[resultIndex - 1].totalTime);
        
    }
    // free(result.arr);
    // for( int i = 0; i < buildCount; i++){
    //     free(graph[i].arr);
    // }
    return 0;
}



// #include <stdio.h>
// #include <stdlib.h>

// // #include <malloc.h>
// typedef struct 
// {
//     int * totalTime;
//     int count;
// }curentTime;

// void main(){
//     int repeatCount;
//     int buildCount,buildRule;
//     curentTime times[1001];
//     int buildDelay[1001];
//     int buildDuration;
//     int beforeBuild, afterBuild;
//     int startPoint;

//     int longest = 0,node;
//     scanf("%d",&repeatCount); //total repeat times
//     for(int repeat = 0; repeat < repeatCount; repeat++){
//         scanf("%d %d",&buildCount,&buildRule); //get buildCount buildRules
//         for(int i = 0;i<buildCount;i++){
//             scanf("%d",&buildDuration);
//             buildDelay[i] = buildDuration;
//             times[i].count = 0;
//         }
//         for(int i = 0;i<buildRule;i++){
//             scanf("%d %d",&beforeBuild,&afterBuild);
//             beforeBuild--; //index시작이 0인것을 감안하여 1을 뺴준다.
//             afterBuild--;
//             if(times[beforeBuild].count == 0){
//                 times[beforeBuild].totalTime = (int *)malloc(sizeof(int)*(++times[beforeBuild].count)); //dynatic allocation to store previous building values
//                 times[beforeBuild].totalTime[times[beforeBuild].count - 1] = buildDelay[beforeBuild]; //store delay in first init
//             }
//             if(times[beforeBuild].count == 0)
//                 times[afterBuild].totalTime = (int *)malloc(sizeof(int)*(++times[afterBuild].count)); //dynatic allocation to store previous building values
//             else
//                 times[afterBuild].totalTime = (int *)realloc(times[afterBuild].totalTime,sizeof(int)*(++times[afterBuild].count)); //dynatic allocation to store previous building values
//             times[afterBuild].totalTime[times[afterBuild].count - 1] = buildDelay[afterBuild]; //store delay when new dynamic allocation is appear

//             int tempBiggest = 0; 
//             for(int i = 0; i < times[beforeBuild].count;i++){
//                 if(tempBiggest < times[beforeBuild].totalTime[i])
//                     tempBiggest = times[beforeBuild].totalTime[i];
//             }
//             times[afterBuild].totalTime[times[afterBuild].count - 1] += tempBiggest;
//         }
//         scanf("%d",&startPoint);
//         int biggestResult = 0;
//         for(int i =0;i < times[startPoint - 1].count;i++){
//             if(biggestResult < times[startPoint - 1].totalTime[i])
//                 biggestResult = times[startPoint - 1].totalTime[i];
//         }
//         printf("%d\n",biggestResult);
//     }
//     return 0;
// }