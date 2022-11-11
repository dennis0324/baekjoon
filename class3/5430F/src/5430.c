#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100005
int rotate;
int mode = 1;
int able = 1;

void print(int * que,int start, int end){
    if(!able) printf("error\n");
    else{
        if(mode < 0){
            start--;end--;
        }
        printf("[");
        for(;start != end; start += mode){
            printf("%d",que[start]);
            if(start != end - mode) printf(",");
        }
        printf("]\n");
    }
}

int main(){
    int c;
    scanf("%d",&c);
    for(int i = 0; i < c; i++){
        int front = 0,rear = 0;
        mode = 1; able = 1;
        int que[MAX_SIZE] = {0};
        char charFunc[MAX_SIZE] = {0};
        scanf("%s %d%*c",charFunc,&rotate);
        for(int j = 0; j < rotate; j++){
            scanf("%*c%d",&que[rear++]);
        }
        scanf("%*s");
        int length = strlen(charFunc);
        for(int j = 0; j < length; j++){
            if(charFunc[j] == 'R'){
                mode *= -1;
                int temp = mode;
            }
            else if(charFunc[j] == 'D'){
                if(mode > 0) front++;
                else rear--;
                if(front > rear) able = 0;
            }
        }

        if(mode > 0) print(que,front,rear);
        else print(que,rear,front);
    }
}


// #include <stdio.h>
// #include <ctype.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_SIZE 100005

// int main(){
    
//     int total, count;
//     int oper = 1;
//     int * start, *end;
//     int rear;
//     scanf("%d",&total);
//     for(int i = 0 ; i < total; i++){
//         int que[MAX_SIZE] = {0};
//         int * queStart = que;
//         int able = 1;
//         char char_function[MAX_SIZE] ={0};
//         rear = 0;
//         scanf("%s",char_function);
//         scanf("%d%*c",&count);
//         for(int j = 0; j < count ; j++){
//             scanf("%*c%d",&que[rear++]);
//         }
//         scanf("%*s");
//         if(count == 0 || que[0] == '\0'){
//             able = 0;
//         }
//         int * queEnd = &que[count - 1];
//         for(int j = 0 ; j < strlen(char_function); j++){
//             switch (char_function[j])
//             {
//             case 'D':
//                 if(!able) break;
//                 if(queStart == queEnd){
//                     //no
//                     able = 0;
//                 }
//                 if(oper > 0 ){
//                   queStart += oper;
//                   start = queStart; 
//                   end = queEnd;
//                 } 
//                 else {
//                     queEnd += oper;
//                     start = queEnd;
//                     end = queStart;
//                 }
//                 break;
//             case 'R':
//                 oper *= -1;
//                 break;
//             }
//         }
//         if(!able){
//             printf("ERROR\n");
//             continue;
//         }

//         printf("[");
//         for(;;){
//             printf("%d",*start);
//             if(start == end) break;
//             printf(",",*start);
//             start += oper;
//         }
//         printf("]\n");
//     }
//     return 0;
// }
