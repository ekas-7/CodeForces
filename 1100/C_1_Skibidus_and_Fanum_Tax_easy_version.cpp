#include <bits/stdc++.h>
#define ll long long
using namespace std;



void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    sort(b.begin(), b.end());

    a[0] = min(a[0], b[0] - a[0]);
    
    bool possible = true;
    for (int i = 1; i < n; ++i) {
        long long best = 3e18;
        
        if (a[i] >= a[i-1]) best = a[i];
        
        auto it = lower_bound(b.begin(), b.end(), a[i-1] + a[i]);
        if (it != b.end()) {
            best = min(best, *it - a[i]);
        }
        
        if (best == 3e18) {
            possible = false;
            break;
        }
        a[i] = best;
    }

    if (possible) cout << "YES\n";
    else cout << "NO\n";
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