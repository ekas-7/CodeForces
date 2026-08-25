#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void slv() {
    int n;
    cin >> n;
    vector<ll> a(n), f(n+2, 0), c(n+2, 0);
    ll s1 = 0, s2 = 0, w = 0, ans = 0;
    
    for(int i=0; i<n; ++i) {
        cin >> a[i];
        f[a[i]]++;
        s1 += a[i] * i;
    }
    
    for(int i=n; i>0; --i) {
        w += f[i];
        c[i] = w;
    }
    
    for(int i=1; i<=n; ++i) {
        if(c[i]) s2 += c[i] * (2LL * n - c[i] - 1) / 2;
    }
    
    ll b = s2 - s1;
    for(int i=0; i<n; ++i) {
        if(i - n + c[a[i]] > ans) ans = i - n + c[a[i]];
    }
    
    cout << b + ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) slv();
    return 0;
}