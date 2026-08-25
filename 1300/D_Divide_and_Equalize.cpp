#include<bits/stdc++.h>
using namespace std;


const int N = 1000000 + 1;
int spf[N];

void sieve() {
    for (int i = 0; i < N; i++) spf[i] = i;

    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

void solve(){


    int n;
    cin >> n;
    vector<long long > a(n);
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int x = a[i];

        while (x > 1) {
            int p = spf[x];
            while (x % p == 0) {
                mp[p]++;
                x /= p;
            }
        }
    }

    bool possi = true;
    for (auto it : mp) {
        if (it.second % n != 0) {
            possi = false;
            break;
        }
    }

    if (possi) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    

}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    long long t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}