#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> s(n + 1, 0), l(n + 1, 0);
    int tl = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1) {
            l[i] = 1;
            tl++;
        }
    }

    auto d1 = [&](auto& f, int u, int p) -> void {
        s[u] = l[u];
        for (int v : g[u]) {
            if (v != p) {
                f(f, v, u);
                s[u] += s[v];
            }
        }
    };
    d1(d1, 1, 0);

    long long bc = 0;
    for (int i = 2; i <= n; ++i) {
        if (s[i] & 1) bc++; 
    }

    if (tl % 2 == 0) {
        cout << bc << "\n";
        return;
    }

    long long res = -1;
    auto d2 = [&](auto& f, int u, int p, long long cc) -> void {
        if (l[u]) {
            if (res == -1 || cc < res) res = cc;
        }
        for (int v : g[u]) {
            if (v != p) {
                f(f, v, u, cc + (s[v] % 2 == 0 ? 1 : -1));
            }
        }
    };
    d2(d2, 1, 0, bc);
    
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}