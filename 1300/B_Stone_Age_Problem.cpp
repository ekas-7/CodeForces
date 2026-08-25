#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    vector<int> vis(n, 0);

    long long sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    bool tper = false;
    long long last_t = -1;
    int timer = 1;

    while(q--){
        int t;
        cin >> t;

        if(t == 1){
            int i;
            long long v;
            cin >> i >> v;
            i--;

            if(!tper){
                sum += v - arr[i];
                arr[i] = v;
            }
            else{
                if(vis[i] != timer){
                    sum += v - last_t;
                }
                else{
                    sum += v - arr[i];
                }
                arr[i] = v;
                vis[i] = timer;
            }

            cout << sum << "\n";
        }
        else{
            long long x;
            cin >> x;

            sum = 1LL * n * x;
            last_t = x;
            tper = true;
            timer++;      

            cout << sum << "\n";
        }
    }
}

int main(){
    solve();
}