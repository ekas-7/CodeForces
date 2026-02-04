#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    long long k, x;
    cin >> k >> x;

    long long a = x;
    long long b = (1LL << (k + 1)) - x;
    long long target = (1LL << k);
    vector<int> ops;

    while (a != target) {
        if (a < target) {
            b -= a;
            a *= 2;
            ops.push_back(1);
        } else {
            a -= b;
            b *= 2;
            ops.push_back(2);
        }
    }

    cout << ops.size() << "\n";
    for (int i = ops.size() - 1; i >= 0; i--) {
        cout << ops[i] << (i == 0 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif


    ll t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}