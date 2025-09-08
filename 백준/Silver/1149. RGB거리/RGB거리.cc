#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int COLOR = 3;
    vector<vector<int>> costs(n, vector<int>(COLOR));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < COLOR; j++) {
            cin >> costs[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(COLOR, 1e9));
    dp[0] = costs[0];

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < COLOR; j++) {
            for (int k = 0; k < COLOR; k++) {
                if (j == k) continue;
                dp[i+1][k] = min(dp[i+1][k], dp[i][j] + costs[i+1][k]);
            }
        }
    }
    cout << *min_element(dp[n-1].begin(), dp[n-1].end());
}