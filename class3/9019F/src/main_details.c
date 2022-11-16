// #include <stdio.h>
// int n,dest;

// int que[100001];
// int front,rear;
// int index;

// typedef int (*oper)(int num);

// oper a[4];

// inline int D(int index){
//     return (index << 1)% 10000;
// }

// inline int s(int index){
//     return !index ? 9999 : index - 1;
// }

// inline int L(int index){
//     return (index * 10 + index / 1000) % 10000;
// }

// inline int R(int index){
//     return ((index / 10) + (index % 10) * 1000) %10000;
// }

// void bfs(int n){
//     long long vis[10000];
//     int temp;
//     vis[n] = 1;
//     que[++rear] = n;
//     while(front != rear){
//         front = (front + 1) % 10000; 
//         index = que[front];

//         for(int i = 0 ; )
//         temp = (index << 1)% 10000; // D
//         if(!vis[temp]){
//             vis[temp] = vis[index] << 2 | 0; 
//             rear = (rear + 1) % 10000; 
//             que[rear] = temp;
//         }
//         temp = !index ? 9999 : index - 1;//S
//         if(!vis[temp]){
//             vis[temp] = vis[index] << 2 | 1;
//             rear = (rear + 1) % 10000; 
//             que[rear] = temp;
//         }
//         temp = (index * 10 + index / 1000) % 10000;//L
//         if(!vis[temp]){
//             vis[temp] = vis[index] << 2 | 2;
//             rear = (rear + 1) % 10000; 
//             que[rear] = temp;
//         }
//         temp = ((index / 10) + (index % 10) * 1000) %10000;//R
//         if(!vis[temp]){
//             vis[temp] = vis[index] <<2 | 3;
//             rear = (rear + 1) % 10000; 
//             que[rear] = temp;
//         }

//         // if()
//     }

// }
// int loop;
// int main(){
//     scanf("%d",&loop);
    
//     for(int i = 0 ; i < loop;i++){
//         scanf("%d %d",&n,&dest);
//         bfs(n);
//         long long check = vis[dest];
//         while(check > 1){
//             int temp = check & 3;
//             if(temp == 0) printf("D");
//             else if(temp == 1) printf("S");
//             else if(temp == 2) printf("L");
//             else if(temp == 3) printf("R");
//             check >>= 2;
//         }
//         printf("\n");
//     }

//     return 0;
// }