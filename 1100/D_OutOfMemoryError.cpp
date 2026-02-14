#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, m, h;
    cin >> n >> m >> h;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    vector<ll> offset(n, 0);
    vector<ll> last_reset(n, 0);

    ll global_reset = 1;

    while (m--) {
        ll b, c;
        cin >> b >> c;
        b--;

        if (last_reset[b] < global_reset) {
            offset[b] = 0;
            last_reset[b] = global_reset;
        }

        offset[b] += c;

        if (offset[b] > h - a[b]) {
            global_reset++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (last_reset[i] < global_reset)
            cout << a[i] << " ";
        else
            cout << a[i] + offset[i] << " ";
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