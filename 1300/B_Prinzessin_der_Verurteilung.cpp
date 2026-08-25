#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;


    for (char c = 'a'; c <= 'z'; c++) {
        string t(1, c);
        if (s.find(t) == string::npos) {
            cout << t << "\n";
            return;
        }
    }


    for (char c1 = 'a'; c1 <= 'z'; c1++) {
        for (char c2 = 'a'; c2 <= 'z'; c2++) {
            string t = ""; t += c1; t += c2;
            if (s.find(t) == string::npos) {
                cout << t << "\n";
                return;
            }
        }
    }


    for (char c1 = 'a'; c1 <= 'z'; c1++) {
        for (char c2 = 'a'; c2 <= 'z'; c2++) {
            for (char c3 = 'a'; c3 <= 'z'; c3++) {
                string t = ""; t += c1; t += c2; t += c3;
                if (s.find(t) == string::npos) {
                    cout << t << "\n";
                    return;
                }
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}