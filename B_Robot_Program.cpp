#include <bits/stdc++.h>
#define ll long long
using namespace std;



void solve() {
    ll n,x,k;
    cin>>n>>x>>k;

    string s;
    cin>>s;

    for (int i = 0; i < n; ++i) {
      x += (s[i] == 'L' ? -1 : +1);
      --k;
      if (!x) break;
    }
    ll ans = 0;
    if (!x) {
      ans = 1;
      for (int i = 0; i < n; ++i) {
        x += (s[i] == 'L' ? -1 : +1);
        if (!x) {
          ans += k / (i + 1);
          break;
        }
      }
    }
    cout << ans << '\n';


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