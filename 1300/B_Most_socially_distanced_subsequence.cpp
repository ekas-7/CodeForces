#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<long long > a(n);
    vector<long long > b(n,1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    

    for(int i=1;i<n-1;i++){
        if(abs(a[i]-a[i-1]) + abs(a[i]-a[i+1]) <= abs(a[i-1]-a[i+1])){
            b[i] = 0;
        }  
    }
    long long ans = 0;
    for(auto i=0;i<n;i++){
        if(b[i]){
            ans++;
        }
    }
    cout<<ans<<"\n";
    for(auto i=0;i<n;i++){
        if(b[i]){
            cout<<a[i]<<" ";
        }
    }
    cout<<"\n";

   
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