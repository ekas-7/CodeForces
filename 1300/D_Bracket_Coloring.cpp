#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n ;
    cin >> n;
    string s;
    cin >> s;
    int open = 0, close = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') open++;
        else close++;
    }

    if(open != close){
        cout << -1 << endl;
        return;
    }

    vector<int> balance(n);
    vector<int> ans(n);
    int b = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') b++;
        else b--;
        balance[i] = b;
    }

    bool posi = true;
    for(int i = 0; i < n; i++){
        if(balance[i] < 0) posi = false;
        else if(balance[i] > 0) posi = true;
        if(posi) ans[i] = 1;
        else ans[i] = 2;
    }
    set<int> st;
    for(auto it : ans) st.insert(it);
    cout << st.size() << endl;
    if(st.size() == 1){
        for(int i = 0; i < n; i++){
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }

    
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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