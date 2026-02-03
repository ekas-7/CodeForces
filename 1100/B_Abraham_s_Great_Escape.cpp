#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n * n - 1 == k) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    vector<string> matrix(n, string(n, 'U'));

    int remaining_cells = n * n - k;
    int blocked_rows = remaining_cells / n;
    int partial_blocked = remaining_cells % n;

    for (int i = n - 1; i > n - 1 - blocked_rows; i--) {
        for (int j = 0; j < n - 1; j++) matrix[i][j] = 'R';
        matrix[i][n - 1] = 'L';
    }

    int par_row = n - 1 - blocked_rows;
    if (par_row >= 0 && partial_blocked > 0) {
        if (par_row != n - 1) {
            for (int i = 0; i < partial_blocked; i++) matrix[par_row][i] = 'D';
        } else {
            for (int i = 0; i < partial_blocked - 1; i++) matrix[par_row][i] = 'R';
            matrix[par_row][partial_blocked - 1] = 'L';
        }
    }

    for (const string& s : matrix) {
        cout << s << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}