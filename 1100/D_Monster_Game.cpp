#include <bits/stdc++.h>
#define ll long long
using namespace std;



void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<long long> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a.rbegin(), a.rend());

    long long max_score = 0;
    long long required_swords = 0;

    for (int k = 1; k <= n; k++) {
        required_swords += b[k - 1];
        if (required_swords > n) break;
        
        long long x = a[required_swords - 1];
        max_score = max(max_score, (long long)k * x);
    }
    
    cout << max_score << "\n";
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