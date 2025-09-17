#include "bits/stdc++.h"
using namespace std;

struct MyMatrix {
    vector<vector<long long>> data;
    int n;

    MyMatrix(int n) : n(n) {
        data.assign(n, vector<long long>(n, 0));
    }

    MyMatrix(const vector<vector<long long>>& d) {
        data = d;
        n = d.size();
    }

    MyMatrix operator*(const MyMatrix& other) const {
        MyMatrix result(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum % 1000;
            }
        }
        return result;
    }
};

MyMatrix power(MyMatrix base, long long exp) {
    int n = base.n;

    MyMatrix I(n);
    for (int i = 0; i < n; i++) I.data[i][i] = 1;

    if (exp == 0) return I;
    if (exp == 1) return base;

    MyMatrix half = power(base, exp / 2);
    if (exp % 2 == 0) return half * half;
    else return half * half * base;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long b;
    cin >> n >> b;

    vector<vector<long long>> arr(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            arr[i][j] %= 1000;
        }
    }

    MyMatrix A(arr);
    MyMatrix R = power(A, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << R.data[i][j] % 1000 << " ";
        }
        cout << "\n";
    }
}