#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> cost_value_pair(n);
    for(int i=0;i<n;i++){
        int cost;
        cin >> cost;
        cost_value_pair[i].first = cost;
    }

    for(int i=0;i<n;i++){
        int value;
        cin >> value;
        cost_value_pair[i].second = value;
    }

    sort(cost_value_pair.begin(), cost_value_pair.end(), [](const auto& a, const auto& b) {
        return (a.second - a.first) < (b.second - b.first);
    });

    int ans = 0;

    int i =0,j=n-1;

    while(i<j){
        if(cost_value_pair[i].second + cost_value_pair[j].second >= cost_value_pair[i].first + cost_value_pair[j].first){
            ans++;
            i++;
            j--;
        }
        else{
            i++;
        }
    }

    cout << ans << endl;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}