#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    ll cost = LLONG_MAX; 
    int i = 0;
    while(i < n) {
        ll local_cost = 0;
        
        if(i != 0) {
            local_cost += (ll)i * a[i];
        }

        while(i + 1 < n && a[i] == a[i+1]) {
            i++;
        }

        if(i != n - 1) {
            local_cost += (ll)(n - 1 - i) * a[i];
        }

        cost = min(cost, local_cost);
        i++;
    }
    cout << cost << "\n";
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