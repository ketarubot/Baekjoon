#include <stdio.h>

#define MAX_DIST 10000000
#define MAX_POS 100001

int queue[MAX_POS];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}


int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int dist[MAX_POS];
    for (int i = 0; i < MAX_POS; i++) dist[i] = MAX_DIST;

    dist[n] = 0;
    enqueue(n);
    while (!isEmpty()) {
        int x = dequeue();
        if (x-1 >= 0) {
            if (dist[x-1] > dist[x]+1) {
                dist[x-1] = dist[x]+1;
                enqueue(x-1);
            }
        }
        if (x+1 < MAX_POS) {
            if (dist[x+1] > dist[x]+1) {
                dist[x+1] = dist[x]+1;
                enqueue(x+1);
            }
        }
        if (x*2 < MAX_POS) {
            if (dist[x*2] > dist[x]+1) {
                dist[x*2] = dist[x]+1;
                enqueue(x*2);
            }
        }
    }
    printf("%d", dist[k]);
}