#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

Node **adj = NULL;
bool *visited = NULL;
int component_count = 0;

void dfs(int start);

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    adj = malloc(sizeof(Node*) * (n+1));
    visited = malloc(sizeof(bool) * (n+1));
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        adj[i] = NULL;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        Node *newNode1 = malloc(sizeof(Node));
        newNode1->vertex = v;
        newNode1->next = adj[u];
        adj[u] = newNode1;

        Node *newNode2 = malloc(sizeof(Node));
        newNode2->vertex = u;
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            component_count++;
        }
    }

    for (int i = 1; i <= n; i++) {
        Node *cur = adj[i];
        while (cur) {
            Node *temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(adj);
    free(visited);
    printf("%d\n", component_count);
}

void dfs(int start) {
    visited[start] = true;
    Node *cur = adj[start];
    while (cur) {
        if (!visited[cur->vertex])
            dfs(cur->vertex);
        cur = cur->next;
    }
}