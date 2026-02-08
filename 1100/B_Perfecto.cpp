#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isSquare(long long x) {
    long long s = round(sqrt(x));
    return s * s == x;
}

void solve() {
    int n;
    cin >> n;
    long long totalSum = 1LL * n * (n + 1) / 2;
    
    if (isSquare(totalSum)) {
        cout << -1 << "\n";
        return;
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    long long currentSum = 0;
    for (int i = 0; i < n; i++) {
        if (isSquare(currentSum + p[i])) {
            swap(p[i], p[i + 1]);
        }
        currentSum += p[i];
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


     #ifndef ONLINE_JUDGE

    freopen("input1.txt", "r", stdin);

    freopen("output1.txt", "w", stdout);

    #endif 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}