#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<int> bits(31,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<31; j++){
            if(a[i] & (1<<j)){
                bits[j]++;
            }
         }
    }

    vector<int> ans(31,0);

    for(int i=30; i>=0; i--){
        int value = bits[i];
        int diff = n - value;
        if(diff <= k){
            k -= diff;
            ans[i] = 1;
        }
    }
    int global_and = 0;

    for(int i=0; i<31; i++){
        if(ans[i]){
            global_and |= (1<<i);
        }
    }
    cout << global_and << "\n";
    
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