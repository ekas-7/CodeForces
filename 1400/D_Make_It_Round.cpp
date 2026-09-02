#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n, m;
    cin >> n >> m;
    long long n_copy = n;
    long long n_2 = 0, n_5 = 0;
    while(n_copy %2 == 0){
        n_2++;
        n_copy /= 2;
    }
    n_copy = n;
    while(n_copy %5 == 0){
        n_5++;
        n_copy /= 5;
    }

    if(n_2 > n_5){
        n_2 -= n_5;
        n_5 = 0;
    }
    else{
        n_5 -= n_2;
        n_2 = 0;
    }

    long long mul = 1;
    while(mul * 5 <= m && n_2 > 0){
        mul *= 5;
        n_2--;
    }

    while(mul * 2<= m && n_5 > 0){
        mul *= 2;
        n_5--;
    }
    while(mul * 10 <= m){
        mul *= 10;
    }

    if (mul == 1) {
        cout << n * m << "\n";
    } else {
        long long max_k = (m / mul) * mul;
        cout << n * max_k << "\n";
    }
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