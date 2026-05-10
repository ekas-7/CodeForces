#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    vector<bool> is_VU(n + 1, false);
    for (int i = n - k + 1; i <= k; ++i) {
        is_VU[a[i]] = true;
    }

    vector<bool> used(n + 1, false);
    bool possible = true;

    for (int i = 1; i <= n; ++i) {
        if (i <= n - k || i > k) {
            if (b[i] != -1 && b[i] != a[i]) {
                possible = false;
                break;
            }
        } else {
            if (b[i] != -1) {
                if (!is_VU[b[i]] || used[b[i]]) {
                    possible = false;
                    break;
                }
                used[b[i]] = true;
            }
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}