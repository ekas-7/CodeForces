#include <bits/stdc++.h>
using namespace std;

void solve(){
    int s, n;
    cin >> s >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    priority_queue<int> pq;

    for(int i = 0; i < n - 1; i++){
        pq.push(a[i+1] - a[i] - 1);
    }
    pq.push(s - a[n-1] + a[0] - 1);  

    int safe = 0;
    int diff = 0; 
    
    while(!pq.empty()){
        int rem = pq.top() - diff; 
        pq.pop();
        
        if(rem <= 0){
            break; 
        }
        
        if(rem == 1){
            safe += 1;
            diff += 2; 
        } else {
            safe += (rem - 1); 
            diff += 4; 
        }
    }
    
    cout << s - safe << endl;
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