#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;

    long long ans =0;

    if((n& n-1) == 0){
        cout << 2 *n-1 << "\n";
        return;
    }
    vector<long long> set_bits;
    for(int i=0; i<64; i++){
        if((n>>i) & 1){
            set_bits.push_back(i);
        }
    }

    for(int i=0; i<set_bits.size(); i++){
      
        ans += 2 * (1LL << (set_bits[i])) - 1;
    }
 
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}