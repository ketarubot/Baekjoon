#include <stdio.h>
#include <string.h>

#define MAX 10000

int visited[MAX];
int prev[MAX];
char how[MAX];
int queue[MAX];

int D(int x) { return 2 * x % 10000; }
int S(int x) { return x == 0 ? 9999 : x - 1; }
int L(int x) { return x % 1000 * 10 + x / 1000; }
int R(int x) { return x % 10 * 1000 + x / 10; }

void bfs(int a, int b) {
    int front = 0, rear = 0;
    queue[rear++] = a;
    visited[a] = 1;
    prev[a] = -1;

    while (front < rear) {
        int cur = queue[front++];

        if (cur == b) break;

        int next;
        next = D(cur);
        if (!visited[next]) {
            visited[next] = 1;
            prev[next] = cur;
            how[next] = 'D';
            queue[rear++] = next;
        }
        next = S(cur);
        if (!visited[next]) {
            visited[next] = 1;
            prev[next] = cur;
            how[next] = 'S';
            queue[rear++] = next;
        }
        next = L(cur);
        if (!visited[next]) {
            visited[next] = 1;
            prev[next] = cur;
            how[next] = 'L';
            queue[rear++] = next;
        }
        next = R(cur);
        if (!visited[next]) {
            visited[next] = 1;
            prev[next] = cur;
            how[next] = 'R';
            queue[rear++] = next;
        }
    }

    char ans[10005];
    int idx = 0;
    int cur = b;
    while (prev[cur] != -1) {
        ans[idx++] = how[cur];
        cur = prev[cur];
    }
    ans[idx] = '\0';

    for (int i = idx - 1; i >= 0; i--) {
        putchar(ans[i]);
    }
    putchar('\n');
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);

        memset(visited, 0, sizeof(visited));
        bfs(a, b);
    }
    return 0;
}