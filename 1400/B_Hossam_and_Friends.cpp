#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;  
    
    vector<int> min_next(n + 1, n + 1);
    while(m--){
        int x, y;
        cin >> x >> y;
        if(y < x) swap(x, y);
        min_next[x] = min(min_next[x], y);
    }

    long long ans = 0;
    int limit = n + 1; 
    
    for(int i = n; i >= 1; i--){
        limit = min(limit, min_next[i]); 
        ans += (limit - i); 
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}