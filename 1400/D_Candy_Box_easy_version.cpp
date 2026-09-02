#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<long long> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int max_ele = *max_element(a.begin(), a.end());

    vector<pair<long long, long long>> freq(max_ele + 1, {0, 0});

    for(int i=0; i<n; i++){
        freq[a[i]].second++;
    }

    vector<pair<long long, long long>> ans;

    for(int i=0; i<=max_ele; i++){
        if(freq[i].second > 0){
            ans.push_back({i, freq[i].second});
        }
    }

    sort(ans.begin(), ans.end(), [](pair<long long, long long> &a, pair<long long, long long> &b){
        return a.second > b.second;
    });

    long long last = ans[0].second;
    long long total = 0;
    
    for(int i=0; i<ans.size(); i++){
        if(ans[i].second >= last){
            total += last;           
            last--;                 
        }
        else{
            total += ans[i].second; 
            last = ans[i].second - 1; 
        }
        
        if(last < 0){                
            break;
        }
    }

    cout << total << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}