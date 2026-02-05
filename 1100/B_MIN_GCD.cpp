#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll get_gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    ll target = a[0];
    ll current_gcd = 0;
    bool possible = false;

    for (int i = 1; i < n; i++) {
        if (a[i] == target) {
            possible = true; 
            break;
        }
        if (a[i] % target == 0) {
            if (current_gcd == 0) current_gcd = a[i];
            else current_gcd = get_gcd(current_gcd, a[i]);
        }

        if (current_gcd == target) {
            possible = true;
            break;
        }
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