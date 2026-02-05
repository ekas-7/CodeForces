#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

void solve(){
    int n, k; 
    cin >> n >> k;
        
        vector <int> a(n);
        for (auto &x : a) cin >> x;
        
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        
        sort(a.begin(), a.end());
        a[n - 1]--;
        sort(a.begin(), a.end());
        
        if (a[n - 1] - a[0] > k || sum % 2 == 0){
            cout << "Jerry\n";
            return;
        }
    cout << "Tom\n";
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}