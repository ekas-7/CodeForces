#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int stringLength = s.length();
    
    for (int i = 1; i < stringLength; ++i) {
    
        if (s[i] == s[i - 1]) {
    
            for (char replacement = 'a'; replacement <= 'z'; ++replacement) {
                if (replacement != s[i - 1] && (i + 1 == stringLength || replacement != s[i + 1])) {
                    s[i] = replacement;
                    break;
                }
            }
        }
    }
    
    cout << s << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}