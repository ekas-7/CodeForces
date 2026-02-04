#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> fib = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
signed char dp[11][151][151][151];

bool isPossi(int n, int w, int h, int l) {
    if (n < 0) return true;
    
    if (w > h) swap(w, h);
    if (h > l) swap(h, l);
    if (w > h) swap(w, h);

    int side = fib[n];
    if (side > w) return false;

    if (dp[n][w][h][l] != -1) return dp[n][w][h][l];

    return dp[n][w][h][l] = isPossi(n - 1, w - side, h, l) || 
                            isPossi(n - 1, w, h - side, l) || 
                            isPossi(n - 1, w, h, l - side);
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    vector<vector<int>> boxes(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2];
    }

    string ans = "";
    for (int i = 0; i < m; i++) {
        int w = boxes[i][0], l = boxes[i][1], h = boxes[i][2];
        ans += (isPossi(n - 1, w, h, l) ? '1' : '0');
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    ll t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}