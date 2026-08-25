#include<bits/stdc++.h>
using namespace std;


bool isPossi(int mid, const vector<long long>& c, long long num){
    return c[mid] < num;
}

void solve(){
    long long n;
    cin >> n;
    vector<long long > a(n);
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<pair<long long, long long>> b;
    vector<long long> c;
    for(long long i = 0; i < n; i++){
        if(i + 1 > a[i]){
            b.push_back({a[i], i + 1});
            c.push_back(i + 1);
        }
    }

    long long ans = 0;
    for(auto p : b){
        long long num = p.first;
        

        int low = 0, high = c.size() - 1;
        int valid_count = 0;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossi(mid, c, num)){
                valid_count = mid + 1; 
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ans += valid_count;
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}