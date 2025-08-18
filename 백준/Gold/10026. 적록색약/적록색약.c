#include <stdio.h>
#include <stdbool.h>

int N;
char grid[100][101], grid_blind[100][101];
bool vis1[100][100], vis2[100][100];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

void dfs(int x, int y, char col, char g[100][101], bool vis[100][100]) {
    vis[x][y] = true;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (!vis[nx][ny] && g[nx][ny] == col) dfs(nx, ny, col, g, vis);
    }
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
        strcpy(grid_blind[i], grid[i]);
        for (int j = 0; j < N; j++)
            if (grid_blind[i][j] == 'G') grid_blind[i][j] = 'R';
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        if (!vis1[i][j]) {
            dfs(i, j, grid[i][j], grid, vis1);
            cnt1++;
        }
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        if (!vis2[i][j]) {
            dfs(i, j, grid_blind[i][j], grid_blind, vis2);
            cnt2++;
        }
    }

    printf("%d %d\n", cnt1, cnt2);
    return 0;
}