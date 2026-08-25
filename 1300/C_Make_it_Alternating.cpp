#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353

vector<long long> p(200005, 0);

void prefix(){
    p[0] = 1;
    for(long long i=1; i<=200000; i++){
        p[i] = (p[i-1]*i)%MOD;
    }
}

void solve(){
    string s;
    cin >> s;

    long long ans = 1;
    long long cnt = 0; 
    long long times = 0; 
    
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1]){
            cnt++;
        } else {
            ans = (ans * (cnt + 1)) % MOD; 
            times += (cnt);      
            cnt = 0;
        }
    }

    ans = (ans * (cnt + 1)) % MOD;
    times += (cnt);

    ans = (ans * p[times]) % MOD;

    cout << times << " " << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    prefix();
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}