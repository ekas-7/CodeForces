#include<bits/stdc++.h>
using namespace std;

vector<int> primes;

void init_sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 3; p <= n; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}

void solve(){
    int n;
    cin >> n;

    if(n%2==0){
        cout << n/2 << " " << n/2 << "\n";
        return;
    }

    int prime = primes[0];
    int i = 1;
    while(prime <= n/2 && i < primes.size()){
        if(n%prime==0){
            cout << n/prime << " " << n - n/prime << "\n";
            return;
        }
        prime = primes[i];
        i++;
    }

    cout << 1 << " " << n - 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    init_sieve(100000);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}