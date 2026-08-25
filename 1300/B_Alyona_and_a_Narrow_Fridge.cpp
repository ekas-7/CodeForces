#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
   
        vector<int> b(a.begin(), a.begin() + i);
        
        sort(b.rbegin(), b.rend());
        
        long long current_height = 0;
        for(int j = 0; j < b.size(); j += 2){
            current_height += b[j];
        }
        
        if(current_height <= h){
            ans = i;
        } else {
            break; 
        }
    }
    
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}