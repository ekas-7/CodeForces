#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long  n;
    cin >> n;
    vector<long long > a(n);
    for (long long  i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(long long  i = 0; i < n; i++) {
        a[i] -= (i + 1);
    }
    map<long long , long long > freq;
    for(long long  i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    long long  ans = 0;
    for(auto [key, value] : freq) {
        ans += value * (value - 1) / 2;
    }
    cout << ans << endl;
}

int  main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long  t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}