#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    
    if (gcd(a, n) == 1 && gcd(b, m) == 1 && gcd(n, m) <= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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