#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long count = 0;
    for (int i = 1; i <= n; i++) {

        long long j = a[i] - i;
        while (j <= i) {
            j += a[i];
        }
        

        for (; j <= n; j += a[i]) {
            if (a[i] * a[j] == i + j) {
                count++;
            }
        }
    }
    cout << count << "\n";
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