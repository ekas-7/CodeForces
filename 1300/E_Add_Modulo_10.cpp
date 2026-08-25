#include<bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int cycle_odd = 0 , cycle_even = 0, stuck_zero = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 10 == 5 || a[i] % 10 == 0){
            if(a[i] % 10 == 5){
                a[i] += 5;
            }
            stuck_zero++;
        }
        else{
            while(a[i] % 10 != 2){
                a[i] += (a[i] % 10);
            }
            
            if((a[i] / 10) % 2 != 0){
                cycle_odd++;
            }
            else{
                cycle_even++;
            }
        }
    }

    if(stuck_zero > 0 && (cycle_odd > 0 || cycle_even > 0)){
        cout << "No" << '\n';
        return;
    }
    
    if(stuck_zero > 0){
        for(int i = 1; i < n; i++){
            if(a[i] != a[0]){
                cout << "No" << '\n';
                return;
            }
        }
        cout << "Yes" << '\n';
        return;
    }

    if(cycle_odd > 0 && cycle_even > 0){
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}