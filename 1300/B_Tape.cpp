#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    

    if (k >= n) {
        cout << n << "\n";
        return;
    }

    priority_queue<int> maxHeap;
    for(int i = 1; i < n; i++){
        maxHeap.push(a[i] - a[i-1]); 
    }   

    int cuts = k - 1; 
    while(cuts > 0 && !maxHeap.empty()){
         maxHeap.pop();
         cuts--;
    }

    int ans = k; 
    while(!maxHeap.empty()){
        ans += maxHeap.top(); 
        maxHeap.pop();
    }

    cout << ans << "\n";    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
}