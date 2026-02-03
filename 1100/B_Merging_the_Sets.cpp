#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<int> cnt(m + 1, 0);
    int cur = 0;
    vector<vector<int>> v(n);

    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        for (int j = 0; j < l; ++j) {
            int x;
            cin >> x;
            if (cnt[x] == 0) cur++;
            cnt[x]++;
            v[i].pb(x);
        }
    }

    int res = (cur == m);

    for (int i = 0; i < n; ++i) {
        for (int x : v[i]) {
            cnt[x]--;
            if (cnt[x] == 0) cur--;
        }

        if (cur == m) res++;

        for (int x : v[i]) {
            if (cnt[x] == 0) cur++;
            cnt[x]++;
        }
    }

    cout << (res >= 3 ? "YES" : "NO") << "\n";
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