#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k >= 3) {
        cout << 0 << "\n";
        return;
    }

    sort(a.begin(), a.end());
    long long min_val = a[0];
    
    for (int i = 0; i < n - 1; i++) {
        min_val = min(min_val, a[i + 1] - a[i]);
    }

    if (k == 1) {
        cout << min_val << "\n";
        return;
    }


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long d = a[j] - a[i];
            min_val = min(min_val, d);
            auto it = lower_bound(a.begin(), a.end(), d);
            
            if (it != a.end()) {
                min_val = min(min_val, *it - d);
            }
            if (it != a.begin()) {
                it--;
                min_val = min(min_val, d - *it);
            }
        }
    }
    cout << min_val << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}