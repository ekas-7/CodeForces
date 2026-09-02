#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    map<long long, pair<vector<long long>, vector<long long>>> mp;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            long long val;
            cin >> val;
            mp[val].first.push_back(i);
            mp[val].second.push_back(j);
        }
    }

    long long ans = 0;
    for(auto& it : mp){
        vector<long long>& x = it.second.first;
        vector<long long>& y = it.second.second;
        
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        long long k = x.size();
        for(long long i = 0; i < k; i++){
        
            ans += x[i] * (2 * i - k + 1);
            ans += y[i] * (2 * i - k + 1);
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    while(t--){
        solve();
    }
    
    return 0;
}