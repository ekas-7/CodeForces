#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n , m;
    cin >> n >> m;
    vector<long long > a ,b;
    for(int i = 0; i<n-1; i++){
        long long x;
        cin >> x;
        a.push_back(x);
    }

    for(int i = 0; i<n; i++){
        long long x;
        cin >> x;
        b.push_back(x);
    }
    a.push_back(1);

    sort(begin(a) , end(a));
    sort(begin(b) , end(b));
    int i = 0 , j = 0;

    while(i<n && j<n){
        if(a[i] < b[j]){
            j++;
            i++;
        }else{
            j++;
        }
    }
    cout << n - i  << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if(cin >> t){
        while(t--){
            solve();
        }
    }
    return 0;
}   