#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long t, h, u;
    cin >> t >> h >> u;
    
    long long ans = (t + h + u) * 3LL;
    long long tu = min(t, u);
    ans -= tu * 2LL;
    t -= tu;
    
    if (h == 0) {
        if (t > 0) ans -= (t - 1);
    } else {
        if (t <= h * 2LL) {
            ans -= t;
        } else {
            ans -= (t - 1);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    if (cin >> tc) {
        while (tc--) {
            solve();
        }
    }
    return 0;
}