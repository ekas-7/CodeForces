#include <bits/stdc++.h>
using namespace std;

int mex(const vector<int>& v, int l, int r) {
    if (l > r) return 0;

    int n = v.size() / 2;
    vector<bool> seen(n + 1, false);

    for (int i = l; i <= r; i++) {
        if (v[i] <= n) seen[v[i]] = true;
    }

    int m = 0;
    while (seen[m]) m++;
    return m;
}

void expand(int l, int r, const vector<int>& v, int sz, int& ans) {
    while (l >= 0 && r < sz && v[l] == v[r]) {
        l--;
        r++;
    }
    ans = max(ans, mex(v, l + 1, r - 1));
}

void solve() {
    int n;
    cin >> n;

    int sz = 2 * n;
    vector<int> v(sz);

    int z1 = -1, z2 = -1;

    for (int i = 0; i < sz; i++) {
        cin >> v[i];
        if (v[i] == 0) {
            if (z1 == -1) z1 = i;
            else z2 = i;
        }
    }

    int ans = 0;

    expand(z1, z1, v, sz, ans);
    expand(z2, z2, v, sz, ans);

    int ml = (z1 + z2) / 2;
    int mr = (z1 + z2 + 1) / 2;

    expand(ml, mr, v, sz, ans);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}