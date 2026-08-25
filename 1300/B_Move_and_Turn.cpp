#include <bits/stdc++.h>
using namespace std;

bool vis[2010][2010][2];
bool ans[2010][2010];

void solve() {
    int n;
    cin >> n;
    
    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push({{1005, 1005}, {0, 0}});
    q.push({{1005, 1005}, {1, 0}});
    vis[1005][1005][0] = true;
    vis[1005][1005][1] = true;

    int cnt = 0;
    while(!q.empty()){
        auto [p, state] = q.front();
        auto [x, y] = p;
        auto [dir, c] = state;
        q.pop();
        
        if (c == n) {
            if (!ans[x][y]) {
                ans[x][y] = true;
                cnt++;
            }
            continue;
        }
        
        if (dir == 0) {
            if (!vis[x+1][y][1]) { 
                vis[x+1][y][1] = true; 
                q.push({{x+1, y}, {1, c+1}}); 
            }
            if (!vis[x-1][y][1]) { 
                vis[x-1][y][1] = true; 
                q.push({{x-1, y}, {1, c+1}}); 
            }
        } else {
            if (!vis[x][y+1][0]) { 
                vis[x][y+1][0] = true; 
                q.push({{x, y+1}, {0, c+1}}); 
            }
            if (!vis[x][y-1][0]) { 
                vis[x][y-1][0] = true; 
                q.push({{x, y-1}, {0, c+1}}); 
            }
        }
    }

    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}