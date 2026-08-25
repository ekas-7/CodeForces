#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long  n;
    cin >> n;
    vector<long long > a(n);
    map<long long ,long long > mp;
    long long sum =0;
    for(long long  i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
        sum += a[i];
    }
    set<long long >s;

    for(long long  i=0; i < n; i++){
        long long  temp = sum - a[i];
        if(temp  & 1 ) continue;
        temp /= 2;

        if(mp[temp] > 0){
            if(temp == a[i] && mp[temp] < 2) continue;
            s.insert(a[i]);
        }

    }
    vector<long long >ans;
    for(long long  i = 0; i < n; i++){
        if(s.find(a[i]) != s.end()){
            ans.push_back(i+1);
        }

    }
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long  t = 1;
    while(t--){
        solve();
    }
}   