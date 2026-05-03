
#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solve() {
    string s, t;
    cin >> s >> t;

    vector<int> s_count(26, 0), t_count(26, 0);
    for (char c : s) s_count[c - 'a']++;
    for (char c : t) t_count[c - 'a']++;

    for (int i = 0; i < 26; i++) {
        if (t_count[i] < s_count[i]) {
            cout << "Impossible\n";
            return;
        }
    }

    string result = "";
    int s_idx = 0;
    int n = s.length();

    for (int i = 0; i < (int)t.length(); i++) {
        for (int c = 0; c < 26; c++) {
            if (t_count[c] > 0) {
                t_count[c]--;
                
                int next_s_idx = s_idx;
                if (next_s_idx < n && (c + 'a') == s[next_s_idx]) {
                    next_s_idx++;
                }

                vector<int> req(26, 0);
                for (int j = next_s_idx; j < n; j++) {
                    req[s[j] - 'a']++;
                }

                bool ok = true;
                for (int j = 0; j < 26; j++) {
                    if (t_count[j] < req[j]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    result += (char)(c + 'a');
                    s_idx = next_s_idx;
                    goto next_pos;
                } else {
                    t_count[c]++;
                }
            }
        }
        next_pos:;
    }
    cout << result << "\n";
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