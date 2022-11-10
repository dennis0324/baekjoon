#include <stdio.h>
#include <stdlib.h>
typedef struct lineData{
    int count;
    int totalTime;
    int arr[1000];
}lineData;
void push(lineData * data,int next){
    (*data).count++;
    (*data).arr[(*data).count - 1] = next;
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
    return 0;
}