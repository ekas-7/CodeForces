#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int a, b;
    if (!(cin >> a >> b)) return;
 
    if (a == b) {
        cout << 0 << "\n";
        return;
    }

    int msb_a = (a > 0) ? (int)log2(a) : -1;
    int msb_b = (b > 0) ? (int)log2(b) : -1;
 
    if (msb_a < msb_b) {
        cout << -1 << "\n";
        return;
    }
 
    if (msb_a == msb_b) {
        cout << 1 << "\n" << (a ^ b) << "\n";
        return;
    }
 
    int x = 0; 
    int y = 0; 
    
    for (int i = 0; i <= msb_a; i++) {
        bool bitA = (a >> i) & 1;
        bool bitB = (b >> i) & 1;
 
        if (bitA && bitB) continue;
        
        if (bitA) x |= (1 << i);
        if (bitB) y |= (1 << i);
    }
 
    cout << 2 << "\n";
    cout << y << " " << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}