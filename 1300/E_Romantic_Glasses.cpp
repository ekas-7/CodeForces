#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long  n;
    cin >> n;
    vector<long long > a(n);
    for(long long  i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<long long > prev_diff(n, -1);
    map<long long , long long > pref_to_index;
    pref_to_index[0] = -1;

    long long  sum = 0;
    bool possi = false;
    for(long long  i=0;i<n;i++){
        if(i & 1){
            sum -= a[i];
        }else{
            sum += a[i];
        }
        // cout<<sum << " ";
        if(pref_to_index.find(sum ) != pref_to_index.end()){
            possi = true;
            break;
        }
        else {
            pref_to_index[sum] = i;
        }
        
    }

    if(possi){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    
}

int  main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
