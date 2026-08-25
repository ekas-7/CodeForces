#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    vector<long long> mp(32, 0);
    
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < 32; j++){
            if(a[i] & (1LL << j)){
                mp[j]++;
            }
        }
    }

    long long ans = 0;
    long long placed = 0;

    while(placed < n){
        ans++;
        long long temp = k;
        for(int i = 31; i >= 0; i--){
            if(mp[i] > 0){
                long long size = 1LL << i;
                long long take = min(mp[i], temp / size);
                mp[i] -= take;
                temp -= take * size;
                placed += take;
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}