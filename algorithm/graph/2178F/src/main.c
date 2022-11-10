#include <stdio.h>
 
typedef struct GraphVertex {
	int value;
	struct GraphVertex* next;
}GraphVertex;
 
typedef struct graph_type {
	int size;
	int total;
	GraphVertex** header;
}GraphType;
 
 
void init(GraphType** g) {
	for (int i = 0; i < (*g)->total; i++) {
		(*g)->header[i] = NULL;
	}
}
GraphType* createGraph(int n) {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	g->total = n;
	g->size = 0;
	g->header = (GraphVertex**)malloc(sizeof(GraphVertex*) * n);
 
	init(&g);
	return g;
}
 
 
void insertVertex(GraphType* g) {
	if (g->size >= g->total) return;
	g->size++;
}
 
void insertEdge(GraphType* g, int start, int end) {
	if (start >= g->total || end >= g->total) return;
	GraphVertex* ge = (GraphVertex*)malloc(sizeof(GraphVertex));
	ge->next = NULL;
	if (!ge) return;
	ge->value = end;
	ge->next = g->header[start];
	g->header[start] = ge;
 
}
 
void deleteGraph(GraphType* g) {
	for (int i = 0; i < g->size; i++) {
		GraphVertex* gv = g->header[i];
		while (gv != NULL) {
			GraphVertex* temp = gv;
			gv = gv->next;
			free(temp);
		}
 
	}
	free(g);
}
 
 
void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->size; i++) {
		GraphVertex* p = g->header[i];
		printf("정점 [%d]", i);
		while (p != NULL) {
			printf("-> %d", p->value);
			p = p->next;
		}
		printf("\n");
	}
}

int bps(int * arr[101],int x,int y){
    int que[100000] = {0};
    int front = 0, rear = 0;

    que[rear++] = 1;
    while(front != rear){

    }
}

int main(){
    GraphType * g = createGraph(100000);
    int x, y;
    scanf("%d %d%*c",&x,&y);
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            // scanf("%1d",&arr[i);
        }
    }

    // bps(arr,0,0);
    return 0;
}