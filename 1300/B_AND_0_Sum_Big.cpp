#include<bits/stdc++.h>
using namespace std;

const long long MOD = 10000009;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

const long long MAX = 200005;
long long fact[MAX], invFact[MAX];
bool precomputed = false;

void precompute() {
    if (precomputed) return;
    fact[0] = 1;
    invFact[0] = 1;
    for (long long i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX - 1] = modInverse(fact[MAX - 1]);
    for (long long i = MAX - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
    precomputed = true;
}

long long nCr(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve(){
    long long n,k;
    cin >> n >> k;

    if(k==0 || n==1){
        cout << 1 << "\n";
        return;
    }

    if( (n & (n-1)) == 0){
        cout<< nCr(n, k-1) % MOD<< "\n";
    }
    else{
        long long f = 1;
        if(k>16){
            f = 5;
        }
        else if(k>8){
            f = 4;
        }
        else if(k>4){
            f = 3;
        }
        else if(k>2){
            f = 2;
        }
        cout<< (nCr(n, k-1) % MOD + f * nCr(n, k-2) % MOD ) % MOD << "\n";
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