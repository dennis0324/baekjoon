#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10001
typedef struct Mat{
    int weight;
    int start;
    int end;
}Mat;

Mat mat[N];
int parent[N],rank[N];
int node, edge,turn,num_compare,a,b, weight,result,min_weight;

int compare(const void * A, const void * B){
    Mat * a = (Mat *)A; Mat * b = (Mat *)B;
    return (a->weight > b->weight) - (a->weight < b->weight);
}

int find(int p) {
    if (p == parent[p]) return p;
    return (parent[p] = find(parent[p]));
}


void set_union(int p, int q) {
    int i = find(p);
    int j = find(q);

    if (i == j) return;

    if (rank[i] < rank[j]) parent[i] = parent[j], rank[j] += rank[i];
    else parent[j] = parent[i], rank[i] += rank[j];
}

int kruskal(int s){
    for(int j = 0 ; j < node; j++) parent[j] = j;
    memset(rank,0,4*edge);

    int length = 0;
    for(int i = s; i < edge; i++){
        Mat e = mat[i];
        if(find(e.start) != find(e.end)){
            length += e.weight;
            set_union(e.start,e.end);
        }
    }
    num_compare = find(s+1);
    for(int j =0; j < node;j++)
        if(num_compare != find(j))
            return 0;
    return length;
}

int main(){
    scanf("%d %d %d",&node,&edge,&turn);
    for(int i = 0; i < edge;i++){
        scanf("%d %d",&a,&b);
        mat[i].start = a - 1;
        mat[i].end = b - 1;
        mat[i].weight = i + 1;
    }
    min_weight = -1;
    for(int i = 0; i < turn; i++){
        if(!min_weight){
            printf("0 ");
            continue;
        }
        min_weight = kruskal(i);
        printf("%d ",min_weight);
    }
    return 0;
}

