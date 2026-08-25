#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n; 
    cin >> n;
    vector<long long> a(n);
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<long long> dp(n, 1);

    for(long long i = n - 1; i >= 0; i--){
        long long j = 2;
        
        while( (i + 1) * j <= n ) { 
            if (a[i] < a[(i + 1) * j - 1]) {
                dp[i] = max(dp[i], 1 + dp[(i + 1) * j - 1]);
            }
            j++;
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}