#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    ll n, x;
    cin >> n >> x;

    ll maxFreeDist = 0;
    ll bestCycleGain = -2e18; 

    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        maxFreeDist += a * (b - 1);
        
        ll currentCycleGain = (a * b) - c;
        bestCycleGain = max(bestCycleGain, currentCycleGain);
    }

    if (maxFreeDist >= x) {
        cout << 0 << "\n";
    } else {
        if (bestCycleGain <= 0) {
            cout << -1 << "\n";
        } else {
            ll remainingDist = x - maxFreeDist;
            ll rollbacksNeeded = (remainingDist + bestCycleGain - 1) / bestCycleGain;
            cout << rollbacksNeeded << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}