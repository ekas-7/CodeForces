#include <bits/stdc++.h>
using namespace std;

const int MAX_PRIME = 31625;
vector<int> primes;
bool is_prime[MAX_PRIME];

long long my_pow(long long base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}   

void seive() {
    fill(is_prime, is_prime + MAX_PRIME, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX_PRIME; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX_PRIME; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p < MAX_PRIME; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}

map<long long, int> getPrimeFactors(long long n) {
    map<long long, int> factors;
    for (long long p : primes) {
        if (p * p > n) break;
        while (n % p == 0) {
            factors[p]++;
            n /= p;
        }
    }
    if (n > 1) {
        factors[n]++;
    }
    return factors;
}

void solve() {
    long long n;
    cin >> n;
    map<long long, int> factors = getPrimeFactors(n);
    
    if(factors.size() >= 3) {
        cout << "YES\n";
        auto it = factors.begin();
        
        long long a = it->first;
        it->second--;
        it++;
        
        long long b = it->first;
        it->second--;
        
        long long c = 1;
        for(auto pair : factors) {
            c *= my_pow(pair.first, pair.second);
        }
        
        cout << a << " " << b << " " << c << "\n";
        return;
    }

    if(factors.size() == 2){
        int cnt = 0;
        for(auto it : factors) {
             cnt += it.second;
        }
    
        if(cnt >= 4) {
            cout << "YES\n";       
            auto it = factors.begin();
            
            long long a = it->first;
            it->second--;
            it++;
            
            long long b = it->first;
            it->second--;
            
            long long c = 1;
            for(auto pair : factors) {
                c *= my_pow(pair.first, pair.second);
            }
            
            cout << a << " " << b << " " << c << "\n";
            return;
        }
        else{
            cout << "NO\n";
        }
        return;
    }

    if(factors.size() == 1) {
        auto it = factors.begin();
        if(it->second >= 6) {
            cout << "YES\n";
            long long a = my_pow(it->first, 1);
            long long b = my_pow(it->first, 2);
            long long c = my_pow(it->first, it->second - 3);
            
            cout << a << " " << b << " " << c << "\n";
            return;
        }
        else{
            cout << "NO\n";
        }
        return;
    }

    cout<<"NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    seive();

    long long t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}