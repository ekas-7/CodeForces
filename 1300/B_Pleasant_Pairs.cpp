#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    map<long long,int> numToInd;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        numToInd[a[i]] = i + 1;
    }

    long long ans = 0;

    for(int i = 0; i < n; i++){
        for(long long v = 1; a[i] * v <= 2 * n; v++){
            if(numToInd.find(v) != numToInd.end()){
                if(a[i] * v == (i + 1) + numToInd[v] && numToInd[v] > i + 1){
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}