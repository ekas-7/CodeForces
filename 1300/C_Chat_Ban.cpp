#include<bits/stdc++.h>
using namespace std;

long long get_emotes(long long m, long long k) {
    if (m <= k) {
        return m * (m + 1) / 2;
    }
    long long rem = 2 * k - 1 - m;
    return k * k - rem * (rem + 1) / 2;
}

void solve() {
    long long k, x;
    cin >> k >> x;
    
    long long l = 1, r = 2 * k - 1, ans = 2 * k - 1;
    
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (get_emotes(mid, k) >= x) {
            ans = mid;
            r = mid - 1; 
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}