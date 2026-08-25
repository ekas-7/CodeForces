#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n , m;
    cin >> n >> m;
    vector<int> a(n);
    map<int,int> modTofreq;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]= a[i] % m;
        modTofreq[a[i]]++;
    }

    int ans = 0;

    for(auto &it : modTofreq){
        // cout<<ans<<"-------------\n"<<it.first<<" "<<it.second<<"\n";
        if(it.first == 0){
            ans++;
            modTofreq[0] = 0;
        }
        else if(it.first * 2 == m){
            ans++;
            modTofreq[it.first] = 0;
        }
        else{
            int freq1 = it.second;
            int freq2 = modTofreq[m - it.first];

            if(freq1 >freq2){
                swap(freq1,freq2);
            }
            if(freq1 == 0 && freq2 == 0){
                continue;
            }
            else if(freq1 == freq2){
                ans++;
            }
            else{
                ans += (freq2 - freq1);
            }
            modTofreq[it.first] = 0;
            modTofreq[m - it.first] = 0;
        }
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