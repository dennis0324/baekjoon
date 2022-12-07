    #include <stdio.h>
    #include <stdlib.h>

    typedef struct Mat{
        int weight;
        int start;
        int end;
    }Mat;

    Mat mat[100001];
    int parent[100001];
    int rank[100001];

    int node, edge;
    int a,b, weight;
    int result;

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

        for(int i = 0 ; i < 100001; i++){
            parent[i] = i;
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

