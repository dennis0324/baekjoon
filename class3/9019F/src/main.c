#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n,dest,index,front,rear,loop;
int que[100001];
char re[100];
typedef int (*oper)(int num);
int D(int num){return (num << 1)% 10000;}
int S(int num){return !num ? 9999 : num - 1;}
int L(int num){return (num * 10 + num / 1000) % 10000;}
int R(int num){return ((num / 10) + (num % 10) * 1000) %10000;}

oper a[4] = {D,S,L,R};

int bfs(int n){
    long long vis[10000] = {0};
    int temp;
    front = 0; rear = 0;
    vis[n] = 1;
    que[++rear] = n;
    while(front != rear){
        front = (front + 1) % 10000; 
        index = que[front];

        for(int i = 0 ; i<4;i++){
            temp = a[i](index);
            if(!vis[temp]){
                vis[temp] = vis[index] << 2 | i; 
                rear = (rear + 1) % 10000; 
                que[rear] = temp;
            }
        }
    }
    return vis[dest];
}

void check_answer(char * asdf,int loop, int n, int dest){
    printf("from: %d to: %d\n",n,dest);
    while(loop--){
        char asdf = re[loop];
        if(asdf == 'D') n = D(n);
        else if(asdf == 'S') n = S(n);
        else if(asdf == 'L') n = L(n);
        else if(asdf == 'R') n = R(n);
        printf("%c : %d\n",asdf,n);
    }
}
int main(){
    scanf("%d",&loop);
    for(int i = 0 ; i < loop;i++){
        int size = 0;
        scanf("%d %d",&n,&dest);
        long long check = bfs(n);
        while(check > 1){
            int temp = check & 3;
            if(temp == 0) re[size++] = 'D';
            else if(temp == 1) re[size++] = 'S';
            else if(temp == 2) re[size++] = 'L';
            else if(temp == 3) re[size++] = 'R';
            check >>= 2;
        }
        while(size--) printf("%c",re[size]);
        printf("\n");
    }

    return 0;
}