#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int h, w;
        cin >> h >> w;

        vector<string> map(h+2);
        for (int i = 1; i < h+1; i++) {
            cin >> map[i];
            map[i] = '.' + map[i] + '.';
        }
        map[0] = string(w+2, '.');
        map[h+1] = string(w+2, '.');
        string s;
        cin >> s;

        vector<bool> hasKey(26, false);
        if (s[0] != '0') {
            for (char c : s) {
                hasKey[c - 'a'] = true;
            }
        }

        h += 2, w += 2;
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {1, -1, 0, 0};
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        vector<vector<pair<int, int>>> door(26);
        q.emplace(0, 0);
        visited[0][0] = true;

        int count = 0;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            char cur = map[y][x];

            if (cur == '$') count++;

            if (islower(cur)) {
                int k = cur - 'a';
                if (!hasKey[k]) {
                    hasKey[k] = true;
                    for (auto [px, py] : door[k]) {
                        if (!visited[py][px]) {
                            q.emplace(px, py);
                            visited[py][px] = true;
                        }
                    }
                    door[k].clear();
                }
            }

            for (int v = 0; v < 4; v++) {
                int nx = x + dx[v];
                int ny = y + dy[v];

                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if (visited[ny][nx] || map[ny][nx] == '*') continue;

                char next = map[ny][nx];
                if (isupper(next)) {
                    int k = next - 'A';
                    if (hasKey[k]) {
                        q.emplace(nx, ny);
                        visited[ny][nx] = true;
                    } else {
                        door[k].emplace_back(nx, ny);
                    }
                } else {
                    q.emplace(nx, ny);
                    visited[ny][nx] = true;
                }
            }
        }
        cout << count << endl;
    }
}