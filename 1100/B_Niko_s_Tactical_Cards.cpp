#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    vector<int>a(n),b(n);
    for(auto &x : a)cin>>x;
    for(auto &x : b)cin>>x;
 
    ll maxi = 0 , mini =0;
    for(int i=0;i<n;i++){
        ll tmaxi = max(maxi-a[i],b[i]-mini);
        ll tmini = min(mini-a[i],b[i]-maxi);
        maxi = tmaxi,mini = tmini;
 
    }
    cout<<maxi<<"\n";
 
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}