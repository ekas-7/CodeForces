#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > c) ans += a - c;
        if (b > d) ans += min(c, a) + (b - d);
    }
    cout << ans << '\n';
}

int main() {
    fast_io();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}