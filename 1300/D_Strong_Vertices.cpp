#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n) ;
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> a[i].second;
    }

    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        if(a[i].first - a[i].second > maxi){
            maxi = a[i].first - a[i].second;
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(a[i].first - a[i].second == maxi){
            ans.push_back(i + 1);
        }
    }
    cout<<ans.size()<<"\n";
    if(ans.size() == 0){
        return;
    }
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
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