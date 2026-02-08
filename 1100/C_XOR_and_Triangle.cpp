#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int x;
    cin >> x;

    int msb = log2(x);
    long long n = x; 

    if ((n & (n - 1)) == 0 || ((n + 1) & n) == 0) {
        cout << -1 << "\n";
        return;
    }

    int y = x ^ (1 << msb);
    for (int i = 0; i < msb; i++) {
        if (!((x >> i) & 1)) {
            y |= (1 << i);
            break;
        }
    }

    cout << y << "\n";
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