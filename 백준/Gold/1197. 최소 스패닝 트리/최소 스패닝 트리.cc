#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    vector<vector<pair<int, int>>> graph(v+1);

    for (int r = 0; r < e; r++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);
    }

    vector<bool> visited(v+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

    q.emplace(0, 1);

    int total_weight = 0;
    while (!q.empty()) {
        auto [w, node] = q.top(); q.pop();

        if (visited[node]) continue;
        visited[node] = true;
        total_weight += w;

        for (auto [weight, vertex]: graph[node]) {
            if (!visited[vertex]) {
                q.emplace(weight, vertex);
            }
        }
    }

    cout << total_weight;
}