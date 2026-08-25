#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long sum = 0;
    for(int i = 0; i < n - 1; i++){
        sum += a[i];
        if(sum <= 0){
            cout << "NO\n";
            return;
        }
    }

    sum = 0;
    for(int i = n - 1; i > 0; i--){
        sum += a[i];
        if(sum <= 0){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}