#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    bool all_c = true;
    for (int i = 0; i < n; i++) {
        if (s[i] != c) {
            all_c = false;
            break;
        }
    }

    if (all_c) {
        cout << 0 << "\n";
        return;
    }

    for (int i = n / 2; i < n; i++) {
        if (s[i] == c) {
            cout << 1 << "\n";
            cout << i + 1 << "\n";
            return;
        }
    }

    cout << 2 << "\n";
    cout << n - 1 << " " << n << "\n";
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