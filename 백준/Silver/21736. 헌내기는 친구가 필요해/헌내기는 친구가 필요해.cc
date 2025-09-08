#include <iostream>
#include <vector>
#include <array>
using namespace std;

array<int, 4> dx = {0, 0, -1, 1};
array<int, 4> dy = {1, -1, 0, 0};
const int V = 4;
int count = 0;

bool is_valid(int x, int y);
void dfs(int x, int y);

int n, m;
vector<string> field;
vector<vector<bool>> visited;
int main() {
    cin >> n >> m;
    field.assign(n, "");
    visited.assign(n, vector<bool>(m, false));

    int si = 0, sj = 0;
    for (int i = 0; i < n; i++) {
        cin >> field[i];
        for (int j = 0; j < m; j++) {
            if (field[i][j] == 'I') {
                si = i;
                sj = j;
            }
        }
    }

    dfs(si, sj);
    if (::count > 0) cout << ::count;
    else cout << "TT";
}

bool is_valid(const int x, const int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y])
        return false;
    return true;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    if (field[x][y] == 'P') ::count += 1;

    for (int v = 0; v < V; v++) {
        int next_x = x + dx[v];
        int next_y = y + dy[v];

        if (is_valid(next_x, next_y) && field[next_x][next_y] != 'X') {
            dfs(next_x, next_y);
        }
    }
}