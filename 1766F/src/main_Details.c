#include <stdio.h>
#include <stdlib.h>

int size;

int * g[32001]; //각 정점이 가지공 있는 다음 정점 
int r[32001]; //각 정점의 진입 차수
int v[32001]; //각 정점의 방문 여부
int e[32001]; //각 정점이 가지고 있는 정점의 개수 
int n,m,a,b;

int que[100001]; //큐 
int count; // 모든 정점의 방문 여부를 확인ㄴ
int front,rear; // front,rear

int main(){
    scanf("%d %d",&n,&m);

    for(int i = 0; i < m;i++){
        scanf("%d %d",&a,&b);
        // 길이가 0이면 그냥 선언 아니면 재할당
        g[a] = e[a] ? realloc(g[a],4 * e[a] + 4) : malloc(4);
        // 할당받은 동적배열의 마지막에 정점 추가
        g[a][e[a]++] = b;
        // 진입 차수 증가
        r[b]++;
    }

    while(1){
        count = 0;
        // 모든 정점 방문 여부 확인 후 작은 수부터 큐 삽입
        for(int i = 1 ; i <= n; i++){
            if(!r[i] && !v[i]){
                if(front != rear) break;
                que[rear++] = i;
                v[i] = 1;
                count++;
            }
        }
        // 모든 정점을 방문 했을 경우 종료
        if(count == 0) break;
        // 큐에서 맨 처음 값 가지고 오기
        int index = que[front++];
        printf("%d ",index);
        // 받은 정점에 대해서 진출 정점의 모음
        int * direction = g[index];
        // 방문한 정점에 대해서 진입차수 감소
        for(int i = 0 ; i < e[index]; i++){
            r[direction[i]]--;
        }
    }

    return 0;
}


