#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fenwick Tree for fast point updates and prefix range queries
struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}
    void add(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<long long> pref(n + 1, 0);
    vector<long long> vals;
    vals.push_back(0); // For l = 1, l-1 = 0

    // Build alternating prefix sum
    for (int i = 1; i <= n; i++) {
        long long val = (i % 2 != 0) ? a[i] : -a[i];
        pref[i] = pref[i - 1] + val;
        vals.push_back(pref[i]);
    }

    // Coordinate Compression
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = vals.size();
    
    auto get_rank = [&](long long x) {
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
    };

    BIT bit_even(m), bit_odd(m);
    bit_even.add(get_rank(0), 1); // Base case: Pref[0] is at an even index
    
    long long ans = 0;

    for (int r = 1; r <= n; r++) {
        int rk = get_rank(pref[r]);
        if (r % 2 != 0) {
            // r is odd, l-1 must be even. We need Pref[r] > Pref[l-1]
            ans += bit_even.query(rk - 1);
            bit_odd.add(rk, 1);
        } else {
            // r is even, l-1 must be odd. We need Pref[r] < Pref[l-1]
            ans += bit_odd.query(m) - bit_odd.query(rk);
            bit_even.add(rk, 1);
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}