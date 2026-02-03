#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
 
void solve() {
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(auto &x: arr)cin>>x;
 
       int dis =2;
       vector<ll>ans;
       ans.push_back(1);
       for(int i=1;i<n;i++){
            ll diff = arr[i]-arr[i-1];
            if(diff==i+1){
                
                ans.push_back(dis);
                dis++;
            }
            else{
                ans.push_back(ans[i-diff]);
            }
       }
       for(auto it:ans)cout<<it<<" ";
 
        cout<<endl;
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
