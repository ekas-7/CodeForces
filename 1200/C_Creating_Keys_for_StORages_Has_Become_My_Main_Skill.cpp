#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl "\n"

void solve() {
    int n, x;
    cin >> x >> n;

    vi ans;
    if(x == 1){
        cout << n << "\n";
        return;
    }

    int bit_op = 0;
    
    for(int i = 0; i <= n && x>0; i++){
        int set_bit = ~(n) & i;
        if(set_bit) break;
        bit_op |= i;
        ans.push_back(i);
        x--;
    }

    if(bit_op!=n&&x>1){
        ans.push_back(~(bit_op) & n == 0 ? n : ~(bit_op) & n);
        x--;
    }
    
    while(x > 0){
        ans.push_back(0);
        x--;
    }

    for(auto it: ans) cout << it << " ";

    cout << "\n";
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}