
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct Mat{
        int weight;
        int start;
        int end;
    }Mat;

    Mat mat[100001];
    int parent[10001];
    int rank[10001];

    int node, edge;
    int a,b, weight;

    int compare(const void * A, const void * B){
        Mat * a = (Mat *)A; Mat * b = (Mat *)B;
        return (a->weight > b->weight) - (a->weight < b->weight);
    }
    int find(int x){
        if (parent[x] == -1) return x;
        while(parent[x] != -1 ) x = parent[x];
        return x;
    }

    int set_union(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y)
        return;

    if(rank[x] < rank[y]) {
        parent[x] = y; // x의 root를 y로 변경
    } else {
        parent[y] = x; // y의 root를 x로 변경

        if(rank[x] == rank[y])
        rank[x]++; // 만약 높이가 같다면 합친 후 (x의 높이 + 1)
    }
    }

    int kruskal(){
        int length = 0;
        qsort(mat,edge,sizeof(Mat),compare);
        int edge_accepted = 0;
        int i = 0;
        while(edge_accepted < node - 1){
            Mat e = mat[i];
            int aSet = find(e.start);
            int bSet = find(e.end);

            if(aSet != bSet){
                length += e.weight;
                edge_accepted++;
                set_union(e.start,e.end);
            }
            i++;
        }
        return length;
    }

    int main(){
        scanf("%d %d",&node,&edge);

        for(int i = 0 ; i < 10000; i++){
            parent[i] = -1;
        }
        for(int i = 0; i < edge;i++){
            scanf("%d %d %d",&a,&b,&weight);
            mat[i].start = a;
            mat[i].end = b;
            mat[i].weight = weight;
        }
        int asdf = kruskal();
        printf("%d",asdf);
        return 0;
    }

