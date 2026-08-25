#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    map<long long, vector<int>> mpp;
    vector<long long> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        mpp[a[i]].push_back(i + 1);
    }

    if(mpp.size() <= 1){
        cout << "NO\n";
        return;
    }

    long long min_freq = LLONG_MAX, min_num = 0;
    for(auto &it : mpp){
        if((long long)it.second.size() < min_freq){
            min_freq = it.second.size();
            min_num = it.first;
        }
    }

    cout << "YES\n";

    vector<int> cand;
    int root = mpp[min_num][0];

    for(auto &it : mpp){
        if(it.first != min_num){
            for(int idx : it.second){
                cout << idx << " " << root << "\n";
                cand.push_back(idx);
            }
        }
    }

    for(int i = 1; i < (int)mpp[min_num].size(); i++){
        cout << cand.back() << " " << mpp[min_num][i] << "\n";
        cand.pop_back();
    }
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