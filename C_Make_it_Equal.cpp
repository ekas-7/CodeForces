#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void solve() {
   int n,k;
   cin>>n>>k;
   vector<int>a(n),b(n);
   for(auto &x: a)cin>>x;
   for(auto &x: b)cin>>x;

    map<int,int> cntS ,cntT;
    for(int i=0;i<n;i++){
        int A = a[i]%k;
        int B = b[i]%k;
        A = min(A,k-A);
        B = min(B,k-B);
        cntS[A]++;
        cntT[B]++;
    }
    if(cntS==cntT){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}