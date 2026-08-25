#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
vector<bool> possible(MAX + 1, false);

void precompute() {
    for (long long r = 2; 1 + r + r * r <= MAX; ++r) {
        long long sum = 1 + r;
        long long term = r * r;
        
        while (sum + term <= MAX) {
            sum += term;
            possible[sum] = true;
            term *= r;
        }
    }
}

void solve(){
    long long n;
    cin>> n;

    if(possible[n]){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute();
    
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}