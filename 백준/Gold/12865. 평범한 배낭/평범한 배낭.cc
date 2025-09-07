#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, max_w;
    cin >> n >> max_w;

    vector<int> dp(max_w+1, 0);
    vector<int> weights(n), values(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    for (int i = 0; i < n; i++) {
        int w = weights[i], v = values[i];
        for (int j = max_w; j >= w; j--) {
            dp[j] = max(dp[j], dp[j-w] + v);
        }
    }
    cout << dp[max_w];
}