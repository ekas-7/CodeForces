#include <bits/stdc++.h>
using namespace std;

int calAND(int l, int r, const vector<vector<int>>& pref) {
    int res = 0;
    int len = r - l + 1;
    for (int j = 0; j < 30; j++) {
        if (pref[r][j] - pref[l - 1][j] == len) {
            res |= (1 << j);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> pref(n + 1, vector<int>(30, 0));
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < 30; j++) {
            pref[i][j] = pref[i - 1][j] + ((a[i] >> j) & 1);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, k;
        cin >> l >> k;
        
        if (a[l] < k) {
            cout << -1 << " ";
            continue;
        }

        int low = l, high = n;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (calAND(l, mid, pref) >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}