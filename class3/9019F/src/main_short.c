// this code is not belongs to me


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int tc, start, end, n;
int q[10001], p[10001], c[10001];
bool visited[10001];
char s[] = " DSLR";

void enq(int x, int y, int z) { if (!visited[x]) { visited[x] = true; q[n++] = x; p[x] = y; c[x] = z; } }
void dfs(int x) {
	if (p[x] >= 0) {
		dfs(p[x]);
		putchar(s[c[x]]);
	}
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &start, &end);
		n = 0;
		memset(visited, 0, sizeof(visited));
        //bfs
		enq(start, -1, 0);
		for (int i = 0; !visited[end]; ++i) {
			enq((q[i] * 2) % 10000, q[i], 1);
			enq((q[i] + 9999) % 10000, q[i], 2);
			enq(q[i]/1000+(q[i] % 1000)*10, q[i], 3);
			enq(q[i]/10+(q[i]%10)*1000, q[i], 4);
		}
        //bfs
		dfs(end);
		putchar('\n');
	}
	return 0;
}