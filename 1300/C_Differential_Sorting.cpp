#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(long long i = 0; i < n; i++) cin >> a[i];

    if(is_sorted(a.begin(), a.end())){
        cout << 0 << "\n";
        return;
    }
    if(a[n-1] < a[n-2]){
        cout << -1 << "\n";
        return;
    }
    if(a[n-1] < 0){          
        cout << -1 << "\n";  
        return;
    }

    vector<vector<long long>> ans;
    for(long long i = n-2; i > 0; i--){
        if(a[i-1] > a[i]){
            ans.push_back({i, i+1, n});
            a[i-1] = a[i] - a[n-1];
        }
    }

    cout << ans.size() << "\n";
    for(auto &it : ans) cout << it[0] << " " << it[1] << " " << it[2] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long  t;
    cin >> t;
    while(t--){
        solve();
    }
}