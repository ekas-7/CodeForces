#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (auto &x : arr) cin >> x;

    ll start_height = arr[k - 1];
    ll max_h = 0;
    set<ll> distinct_heights;

    for (ll x : arr) {
        max_h = max(max_h, x);
        if (x >= start_height) {
            distinct_heights.insert(x);
        }
    }

    ll current_time = 0;
    ll current_h = start_height;

    for (ll next_h : distinct_heights) {
       

        ll travel_time = next_h - current_h;
        if (current_h < current_time + travel_time) {
            cout << "NO" << endl;
            return;
        }
        
        current_time += travel_time;
        current_h = next_h;
    }

    if (current_h == max_h) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE

    freopen("input1.txt", "r", stdin);

    freopen("output1.txt", "w", stdout);

    #endif

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}