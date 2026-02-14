#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<ll, int> dp;

int helper(ll n, ll k) {
    if (n == k) return 0;
    if (n < k || n <= 1) return INT_MAX;

    if (dp.count(n)) return dp[n];

    ll fl = n / 2;
    ll ce = (n + 1) / 2;

    int left = helper(fl, k);
    int right = helper(ce, k);

    int res = min(left, right);
    if (res == INT_MAX) return dp[n] = INT_MAX;

    return dp[n] = 1 + res;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    dp.clear();

    int ans = helper(n, k);

    if (ans == INT_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
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