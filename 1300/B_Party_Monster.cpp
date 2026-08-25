#include <iostream>
#define ll long long

using namespace std;

void solve() {
    int x;
    cin >> x;
    string s;
    cin >> s;
    ll o=0 , c=0;
    for(auto it: s){
        if(it == '(') o++;
        else c++;
    }

    if(o == c) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}