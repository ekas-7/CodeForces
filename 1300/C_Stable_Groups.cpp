#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n, k, x;
    cin >> n >> k >> x;
    vector<long long> a(n);

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> gaps;
    for(long long i = 1; i < n; i++){
        if(a[i] - a[i-1] > x){
            gaps.push_back((a[i] - a[i-1] - 1) / x);
        }
    }

    sort(gaps.begin(), gaps.end());

    long long ans = gaps.size() + 1;
    for(long long gap : gaps){
        if(k >= gap){
            k -= gap;
            ans--;
        } else {
            break;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long t = 1;
    while(t--){
        solve();
    }
    return 0;
}