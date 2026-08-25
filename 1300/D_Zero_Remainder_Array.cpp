#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n , k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map<int, int> freq;

    for(int i = 0; i < n; i++){
        freq[k - (a[i] % k)]++;
    }

    int max_freq = 0 ,max_element = 0;
    for(auto it : freq){
        if(it.first != k){
            if(max_freq < it.second){
                max_freq = it.second;
                max_element = it.first;
            }
            else if(max_freq == it.second){
                max_element = max(max_element, it.first);
            }
        }
    }
    cout << (max_freq == 0 ? 0 : (long long)(max_freq - 1) * k + max_element + 1) << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}