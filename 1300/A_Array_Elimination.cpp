#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
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

    for(int i=1;i<=n;i++){
        bool possible = true;
        for(int j=0;j<31;j++){
            if(bits[j] % i != 0){
                possible = false;
                break;  
            }
        }
        if(possible){
            cout << i << " ";
        }
    }
    cout << "\n";

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