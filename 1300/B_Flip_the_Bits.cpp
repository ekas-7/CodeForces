#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    
  
    vector<int> balance(n);
    int current_balance = 0;
    for (int i = 0; i < n; i++) {
        current_balance += (a[i] == '1' ? 1 : -1);
        balance[i] = current_balance;
    }
    
    bool flipped = false;
  
    for (int i = n - 1; i >= 0; i--) {
        if ((a[i] != b[i]) != flipped) {
            if (balance[i] != 0) {
                cout << "NO\n";
                return;
            }
            flipped = !flipped;
        }
    }
    cout << "YES\n";
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