#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(long long  i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<vector<long long>> two_power_buckets(32);
    for (long long x : a) {
        for (long long  i = 31; i >= 0; i--) {
            if (x & (1LL << i)) {
                two_power_buckets[i].push_back(x);
                break;
            }
        }
    }
    long long  ans = 0;
    for (const auto& bucket : two_power_buckets) {
        if (bucket.size() >= 2) {
            ans += bucket.size() * (bucket.size() - 1) / 2;
        }
    }
    cout << ans << "\n";
}

int  main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}