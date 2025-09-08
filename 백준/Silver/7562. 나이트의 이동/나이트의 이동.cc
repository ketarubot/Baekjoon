#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;

const int V = 8;
array<int, V> vr = {2, 1, -1, -2, -2, -1, 1, 2};
array<int, V> vc = {1, 2, 2, 1, -1, -2, -2, -1};
const int MAX_MOVE = 1e9;

int board_size;
bool in_range(int i, int j);

int main() {
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        cin >> board_size;

        vector<vector<int>> board(board_size, vector<int>(board_size, MAX_MOVE));
        int si, sj;
        cin >> si >> sj;
        int gi, gj;
        cin >> gi >> gj;
        board[si][sj] = 0;

        queue<array<int, 3>> q;
        q.push({1, si, sj});
        while (!q.empty()) {
            auto [c, i, j] = q.front();
            q.pop();

            for (int v = 0; v < V; v++) {
                int ni = vr[v] + i;
                int nj = vc[v] + j;

                if (in_range(ni, nj) && c < board[ni][nj]) {
                    board[ni][nj] = c;
                    q.push({c+1, ni, nj});
                }
            }
        }
        cout << board[gi][gj] << endl;
    }
}

bool in_range(const int i, const int j) {
    if (i < 0 || i >= board_size || j < 0 || j >= board_size) {
        return false;
    }
    return true;
}