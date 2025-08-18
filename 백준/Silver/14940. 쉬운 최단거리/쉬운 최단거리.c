#include <stdio.h>
#include <stdlib.h>

typedef struct { int y, x; } Point;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int **map = malloc(n * sizeof(int *));
    int **dist = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        map[i] = malloc(m * sizeof(int));
        dist[i] = malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            dist[i][j] = -1;
        }
    }

    Point *queue = malloc(n * m * sizeof(Point));
    int front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 2) {
                queue[rear++] = (Point){i, j};
                dist[i][j] = 0;
            }
        }
    }

    while (front < rear) {
        Point p = queue[front++];
        for (int d = 0; d < 4; d++) {
            int ny = p.y + dy[d];
            int nx = p.x + dx[d];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (map[ny][nx] == 0) continue;
            if (dist[ny][nx] == -1) {
                dist[ny][nx] = dist[p.y][p.x] + 1;
                queue[rear++] = (Point){ny, nx};
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                printf("0 ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(map[i]);
        free(dist[i]);
    }
    free(map);
    free(dist);
    free(queue);
}