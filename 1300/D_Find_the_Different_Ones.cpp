#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    vector<int> prev_diff(n, -1);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            prev_diff[i] = i - 1;
        } else {
            prev_diff[i] = prev_diff[i - 1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--; 

        if (prev_diff[r] >= l) {
            cout << prev_diff[r] + 1 << " " << r + 1 << "\n";
        } else {
            cout << "-1 -1\n";
        }
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}