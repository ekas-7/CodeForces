#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int left = 0, sum = 0, best = -1;
    for(int right = 0; right < n; right++){
        sum += a[right];
        while(sum > s){
            sum -= a[left];
            left++;
        }
        if(sum == s){
            best = max(best, right - left + 1);
        }
    }

    if(best == -1){
        cout << -1 << "\n";
    } else {
        cout << n - best << "\n";
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;

}