#include "bits/stdc++.h"
using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

void _union(int a, int b) {
    int a_root = find(a);
    int b_root = find(b);

    if (a_root == b_root) return;

    if (parent[a_root] <= parent[b_root]) {
        parent[a_root] += parent[b_root];
        parent[b_root] = a_root;
    }
    else {
        parent[b_root] += parent[a_root];
        parent[a_root] = b_root;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    parent.assign(n+1, -1);

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(c, a, b);
    }

    sort(edges.begin(), edges.end());

    int total_weight = 0;
    int mw = 0;
    for (auto [w, a, b] : edges) {
        if (find(a) != find(b)) {
            _union(a, b);
            total_weight += w;
            if (w > mw) mw = w;
        }
    }
    total_weight -= mw;

    cout << total_weight;
}