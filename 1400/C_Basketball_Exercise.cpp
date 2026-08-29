#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    long long dp0 = 0; 
    long long dp1 = 0; 

    for(int i = 0; i < n; i++){
        long long new_dp0 = max(dp0, dp1 + a[i]);
        long long new_dp1 = max(dp1, dp0 + b[i]);
        
        dp0 = new_dp0;
        dp1 = new_dp1;
    }

    cout << max(dp0, dp1) << "\n";
    return 0;
}