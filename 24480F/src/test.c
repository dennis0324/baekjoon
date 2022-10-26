// #include <stdio.h>
// #include <stdlib.h>

// #define GRAPH_ADJACENCY_INIT_CAPACITY 12

// typedef struct Graph {
//     struct {
//         int *ptr;
//         int length;
//         int capacity;
//     } *adjacency;
//     int *visited;
//     int vertex_count;
//     int edge_count;
// } Graph;

// Graph *graph_create(int c);
// void graph_release(Graph *g);
// int graph_add_edge(Graph *g, int v, int w);
// void graph_dfs(Graph *g, int v);

// int main(void) {
//     int n, m, r;

//     scanf("%d %d %d", &n, &m, &r);

//     Graph *g = graph_create(n + 1);

//     for (int i = 0; i < m; i++) {
//         int v, w;

//         scanf("%d %d", &v, &w);

//         graph_add_edge(g, v, w);
//     }

//     graph_dfs(g, r);

//     graph_release(g);

//     return 0;
// }

// Graph *graph_create(int c) {
//     Graph *g = malloc(sizeof(*g));

//     g->adjacency = malloc(c * sizeof(*(g->adjacency)));

//     for (int i = 0; i < c; i++) {
//         g->adjacency[i].length = 0;
//         g->adjacency[i].capacity = GRAPH_ADJACENCY_INIT_CAPACITY;

//         g->adjacency[i].ptr = malloc(
//             g->adjacency[i].capacity * sizeof(*(g->adjacency[i].ptr))
//         );
//     }

//     g->visited = malloc(c * sizeof(*(g->visited)));

//     g->vertex_count = c;
//     g->edge_count = 0;

//     return g;
// }

// void graph_release(Graph *g) { 
//     if (g == NULL) return;

//     for (int i = 0; i < g->vertex_count; i++)
//         free(g->adjacency[i].ptr);

//     free(g->visited), free(g->adjacency), free(g);
// }

// int graph_add_edge(Graph *g, int v, int w) {
//     if (g == NULL || v >= g->vertex_count 
//         || w >= g->vertex_count) return 0;

//     if (g->adjacency[v].length >= g->adjacency[v].capacity) {
//         const int new_capacity = 2 * g->adjacency[v].capacity;

//         int *new_ptr = realloc(
//             g->adjacency[v].ptr, 
//             new_capacity * sizeof(*(g->adjacency[v].ptr))
//         );

//         if (new_ptr == NULL) return 0;

//         g->adjacency[v].capacity = new_capacity;
//         g->adjacency[v].ptr = new_ptr;
//     }

//     g->adjacency[v].ptr[g->adjacency[v].length++] = w;

//     if (g->adjacency[w].length >= g->adjacency[w].capacity) {
//         const int new_capacity = 2 * g->adjacency[w].capacity;

//         int *new_ptr = realloc(
//             g->adjacency[w].ptr, 
//             new_capacity * sizeof(*(g->adjacency[w].ptr))
//         );

//         if (new_ptr == NULL) return 0;

//         g->adjacency[w].capacity = new_capacity;
//         g->adjacency[w].ptr = new_ptr;
//     }

//     g->adjacency[w].ptr[g->adjacency[w].length++] = v;

//     g->edge_count++;

//     return 1;
// }

// static void _graph_dfs_helper(Graph *g, int v, int *k) {
//     g->visited[v] = *k;

//     for (int i = 0; i < g->adjacency[v].length; i++) {
//         int w = g->adjacency[v].ptr[i];

//         if (g->visited[w]) continue;

//         _graph_dfs_helper(g, w, ((*k)++, k));
//     }
// }

// static int _compare_values(const void *x, const void *y) {
//     const int i = *(const int *) x, j = *(const int *) y;

//     return (i < j) - (i > j);
// }

// void graph_dfs(Graph *g, int v) {
//     if (g == NULL || v >= g->vertex_count) return;

//     for (int i = 0; i < g->vertex_count; i++) {
//         g->visited[i] = 0;

//         qsort(
//             g->adjacency[i].ptr, 
//             g->adjacency[i].length, 
//             sizeof(*(g->adjacency[i].ptr)), 
//             _compare_values
//         );
//     }

//     int k = 1;

//     _graph_dfs_helper(g, v, &k);

//     for (int i = 1; i < g->vertex_count; i++)
//         printf("%d\n", g->visited[i]);
// }