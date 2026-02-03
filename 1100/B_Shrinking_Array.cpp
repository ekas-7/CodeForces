#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 1; i < n; i++) {
        if (abs(a[i - 1] - a[i]) <= 1) {
            cout << 0 << endl;
            return;
        }
    }
    for (int i = 1; i + 1 < n; i++) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            cout << 1 << endl;
            return;
        }
        if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
            cout << 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}


int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE

    freopen("input1.txt", "r", stdin);

    freopen("output1.txt", "w", stdout);

    #endif

    ll t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}