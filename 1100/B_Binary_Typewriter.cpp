#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

void solve(){
    string s;
    int n;
    cin >> n;
    cin >> s;
    s="0"+s;
    int ans = 0, cur = s[0];
    for (int i = 1; i <= n; i++) {
        int dig = s[i];
        if (cur != dig) 
           ans++;
        cur = dig;
    }
   if(ans>=3)
     cout<< ans-2 + n<<"\n";
   else if(ans==2)
     cout<< ans-1 + n<<"\n";
   else 
     cout<<ans+n<<"\n";
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}