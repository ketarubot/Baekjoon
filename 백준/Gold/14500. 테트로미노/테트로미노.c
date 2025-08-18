#include <stdio.h>

int n, m;
int map[500][500];
int visited[500][500];
int max = 0;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void dfs(int y, int x, int depth, int sum) {
    if (depth == 4) {
        if (sum > max) max = sum;
        return;
    }
    visited[y][x] = 1;
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (!visited[ny][nx]) {
            dfs(ny, nx, depth + 1, sum + map[ny][nx]);
        }
    }
    visited[y][x] = 0;
}

void check_extra_shape(int y, int x) {
    if (y >= 0 && y + 1 < n && x - 1 >= 0 && x + 1 < m) {
        int sum = map[y][x] + map[y][x - 1] + map[y][x + 1] + map[y + 1][x];
        if (sum > max) max = sum;
    }
    if (y - 1 >= 0 && y + 1 < n && x >= 0 && x + 1 < m) {
        int sum = map[y][x] + map[y - 1][x] + map[y + 1][x] + map[y][x + 1];
        if (sum > max) max = sum;
    }
    if (y - 1 >= 0 && y + 1 < n && x - 1 >= 0 && x < m) {
        int sum = map[y][x] + map[y - 1][x] + map[y + 1][x] + map[y][x - 1];
        if (sum > max) max = sum;
    }
    if (y - 1 >= 0 && y >= 0 && x - 1 >= 0 && x + 1 < m) {
        int sum = map[y][x] + map[y][x - 1] + map[y][x + 1] + map[y - 1][x];
        if (sum > max) max = sum;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(i, j, 1, map[i][j]);
            check_extra_shape(i, j);
        }
    }

    printf("%d\n", max);
}