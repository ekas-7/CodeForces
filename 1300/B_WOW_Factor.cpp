#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    long long ans = 0;
    vector<long long> pref(n, 0) , suff(n, 0);
    
    for(int i = 1; i < n; i++){
        pref[i] = pref[i-1];
        if(s[i] == 'v' && s[i-1] == 'v'){
            pref[i]++;
        }
    }
    
    for(int i = n-2; i >= 0; i--){
        suff[i] = suff[i+1];
        if(s[i] == 'v' && s[i+1] == 'v'){
            suff[i]++;
        }
    }

    for(int i = 1; i < n - 1; i++){
        if(s[i] == 'o'){
            ans += pref[i-1] * suff[i+1];
        }
    }
    
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long t = 1;
    while(t--){
        solve();
    }
    return 0;
}