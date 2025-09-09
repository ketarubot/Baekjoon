#include "bits/stdc++.h"
using namespace std;

typedef vector<vector<int>> matrix;
typedef vector<matrix> tensor;

const int DIR = 6;
array<int, DIR> dx = {0, 0, -1, 1, 0, 0};
array<int, DIR> dy = {0, 0, 0, 0, 1, -1};
array<int, DIR> dz = {1, -1, 0, 0, 0, 0};

int c, r, h;
bool in_range(int x, int y, int z) {
    if (x < 0 || x >= c || y < 0 || y >= r || z < 0 || z >= h) {
        return false;
    }
    return true;
}

int main() {
    cin >> c >> r >> h;

    tensor boxes(h, matrix(r, vector<int>(c)));
    queue<array<int, 4>> q;
    int total = 0;
    for (int d = 0; d < h; d++) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> boxes[d][i][j];
                int cur = boxes[d][i][j];
                if (cur >= 0) {
                    total++;
                    if (cur == 1) q.push({j, i, d, 0});
                }
            }
        }
    }

    int max_day = 0;
    int count = 0;
    while (!q.empty()) {
        auto [x, y, z, day] = q.front(); q.pop();
        count++;
        if (day > max_day) max_day = day;

        for (int v = 0; v < DIR; v++) {
            int nx = dx[v] + x;
            int ny = dy[v] + y;
            int nz = dz[v] + z;

            if (in_range(nx, ny, nz) && boxes[nz][ny][nx] == 0) {
                q.push({nx, ny, nz, day+1});
                boxes[nz][ny][nx] = 1;
            }
        }
    }
    cout << (total==count?max_day:-1);
}