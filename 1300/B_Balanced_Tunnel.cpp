#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<long long> a(n) , b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    vector<pair<long long , long long>> v(n + 1, {0 , 0 });
    for(int i = 0; i < n; i++){
        v[a[i]].first = i;
        v[b[i]].second = i;
    }
    long long ans = 0;
    for(int i = 1; i < n+1; i++){
        ans = max(ans , v[i].second - v[i].first);
    }


    cout << ans << endl;
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