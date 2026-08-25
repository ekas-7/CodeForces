#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;

    if(n % 2 == 1){
        int mid = n / 2;
        ans += 0;
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j]) continue;

            int ci = i, cj = j;
            int ones = 0, sz = 0;

            for(int k = 0; k < 4; k++){
                if(!visited[ci][cj]){
                    visited[ci][cj] = true;
                    sz++;
                    if(a[ci][cj] == '1') ones++;
                }
                int ni = cj;
                int nj = n - 1 - ci;
                ci = ni; cj = nj;
            }

            ans += min(ones, sz - ones);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}