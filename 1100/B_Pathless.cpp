#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void solve() {
    int n, s;
    if (!(cin >> n >> s)) return;
    vector<int> steps(n);
    for (auto &step : steps) cin >> step;

    long long totalSum = accumulate(steps.begin(), steps.end(), 0LL);

    if (totalSum > s) {
        sort(steps.begin(), steps.end(), greater<int>());
        for (int i = 0; i < n; i++) {
            cout << steps[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }
    int mod = totalSum+1;
    if(s!=mod){
        cout<<-1<<"\n";
    }
    else{
        int z =0,t =0, o =0;
        for(auto it:steps){
            if(it==0)z++;
            else if(it==1)o++;
            else t++;
        }
        while(z--)cout<<0<<" ";
        while(t--)cout<<2<<" ";
        while(o--)cout<<1<<" ";

        cout<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}