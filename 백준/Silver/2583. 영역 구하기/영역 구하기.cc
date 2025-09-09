#include "bits/stdc++.h"
using namespace std;

const int DIR = 4;
array<int, DIR> dx = {0, 0, -1, 1};
array<int, DIR> dy = {1, -1, 0, 0};

bool in_range(const int x, const int y, const int lx, const int ly) {
    if (x < 0 || x >= lx || y < 0 || y >= ly) return false;
    return true;
}

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<int>> board(m, vector<int>(n, 0));
    for (int r = 0; r < k; r++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        for (int i = sy; i < ey; i++) {
            for (int j = sx; j < ex; j++) {
                board[i][j] = 1;
            }
        }
    }

    vector<int> areas;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) {
                int area = 0;
                queue<array<int, 2>> q;
                q.push({j, i});
                board[i][j] = 1;

                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    area++;

                    for (int v = 0; v < DIR; v++) {
                        int nx = dx[v] + x;
                        int ny = dy[v] + y;

                        if (in_range(nx, ny, n, m) && board[ny][nx] == 0) {
                            q.push({nx, ny});
                            board[ny][nx] = 1;
                        }
                    }
                }
                areas.push_back(area);
            }
        }
    }

    cout << areas.size() << endl;
    sort(areas.begin(), areas.end());
    for (int area: areas) {
        cout << area << ' ';
    }
}