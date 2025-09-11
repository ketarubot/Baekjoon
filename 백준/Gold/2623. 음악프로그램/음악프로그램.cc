#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<int> in_degree(n+1, 0);

    for (int p = 0; p < m; p++) {
        int sing;
        cin >> sing;
        int prev;
        cin >> prev;
        for (int s = 1; s < sing; s++) {
            int num;
            cin >> num;
            graph[prev].emplace_back(num);
            in_degree[num] += 1;
            prev = num;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.emplace(i);
        }
    }

    vector<int> output(n);
    int idx = 0;
    vector<bool> added(n+1, false);
    while (!q.empty()) {
        const auto vertex = q.front(); q.pop();
        if (added[vertex]) {
            cout << 0;
            return 0;
        }
        output[idx++] = vertex;
        added[vertex] = true;
        for (int next: graph[vertex]) {
            in_degree[next] -= 1;
            if (in_degree[next] == 0) {
                q.emplace(next);
            }
        }
    }

    if (idx != n) {
        cout << 0;
        return 0;
    }
    for (int o: output) {
        cout << o << endl;
    }
}