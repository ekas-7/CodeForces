#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n , k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    int i = 0, j = 1;
    long long ans = 0;
    
    while(i < n && j < n){
        while(j < n && a[j] * 2LL > a[j-1]){ 
            if(j - i == k){
                ans++;
                i++; 
            }
            j++; 
        }
        
        if(j < n && a[j] * 2LL <= a[j-1]){
            i = j; 
            j++;  
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}