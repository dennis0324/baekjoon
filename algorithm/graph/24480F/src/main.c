#include <stdio.h>
#include <stdlib.h>

int vertex[100001] = {0};
int v,e,s;
int cnt = 1; 
typedef struct graph_type {
	int size;
	int total;
    struct {
        int * p;
        int capacity;
        int length;
    }*header;
}GraphType;

GraphType* createGraph(int n) {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	g->total = n;
	g->size = 0;
	g->header = malloc(sizeof(*(g->header)) * n);
	return g;
}
 
void insertEdge(GraphType* g, int start, int end) {
	if (g ==NULL || start >= g->total || end >= g->total) return;
    if(!g->header[start].p){
        g->header[start].p = malloc(sizeof(int) * 8);
        g->header[start].length = 0;
        g->header[start].capacity = 8;
    }
    else if(g->header[start].length >= g->header[start].capacity){
        g->header[start].capacity *= 2;
        g->header[start].p = realloc(g->header[start].p,g->header[start].capacity * sizeof(int));
    }
    g->header[start].p[g->header[start].length++] = end;
 
}

int compare (const void* first, const void* second)
{
    if (*(int*)first < *(int*)second)
        return 1;
    else if (*(int*)first > *(int*)second)
        return -1;
    else
        return 0;
}

void dfs(GraphType * g, int vc){
    vertex[vc] = cnt++;
    for(int i = 0; i < g->header[vc].length; i++){
        int w = g->header[vc].p[i];
        if(!vertex[w]){
            dfs(g,w);
        }
    }
}

int main(){
    int e1,e2;
    scanf("%d %d %d",&v,&e,&s);
    GraphType * g = createGraph(v+1);
    g->size = v;
    for(int i =0; i < e; i++){
        scanf("%d %d",&e1,&e2);
        insertEdge(g,e1,e2);
        insertEdge(g,e2,e1);
    }
    for(int i = 1; i < g->total; i++)
        qsort(g->header[i].p,g->header[i].length,sizeof(int),compare);

    dfs(g,s);

    for (int i = 1; i < g->total; i++)
        printf("%d\n", vertex[i]);

    for(int i = 1; i < g->total; i++){
        if(g->header[i].p != NULL)
            free(g->header[i].p);
    }
    free(g->header);
    free(g);
    return 0;
}
