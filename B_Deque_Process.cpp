#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> perm(n);
    for(auto &x : perm) cin >> x;

    int i = 0, j = n - 1;
    vector<char> ans;

    if(perm[i] > perm[j]){
        ans.push_back('L');
        i++;
    }
    else{
         ans.push_back('R');
        j--;
    }

    bool toggleBig = false;

    while(i <= j){
        if(toggleBig){
            if(perm[i] > perm[j]){
                ans.push_back('L');
                i++;
            }
            else{
                ans.push_back('R');
                j--;
            }
            toggleBig = false;
        }
        else{
            if(perm[i] < perm[j]){
                ans.push_back('L');
                i++;
            }
            else{
                ans.push_back('R');
                j--;
            }
            toggleBig = true;
        }
    }


    for(auto c : ans) cout << c;
    cout << "\n";
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