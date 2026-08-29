#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n ;
    cin >> n;
    vector<long long > a(n) ;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    map<long long , long long > mp;
    for(int i=0; i<n; i++){
        mp[a[i]-i]+=a[i];
    }

    long long  ans = 0 ;
    for(auto it: mp){
        ans = max(ans , it.second);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;

        while(t--){
            solve();
        }
    
    return 0;
}