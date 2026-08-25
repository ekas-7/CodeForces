#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    
    map<pair<ll, ll>, ll> freq;
    ll ans = 0;
    
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        
        ll cx = a % x;
        ll cy = a % y;
        ll target_x = (x - cx) % x;
        ll target_y = cy;
    
        ans += freq[{target_x, target_y}];
        freq[{cx, cy}]++;
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}