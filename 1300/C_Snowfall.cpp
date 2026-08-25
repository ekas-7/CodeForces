#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> six, two, three, neither;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 6 == 0) six.push_back(x);
        else if (x % 2 == 0) two.push_back(x);
        else if (x % 3 == 0) three.push_back(x);
        else neither.push_back(x);
    }

    for (int x : six) cout << x << " ";

    if (three.size() < two.size()) {
        for (int x : three) cout << x << " ";
        for (int x : neither) cout << x << " ";
        for (int x : two) cout << x << " ";
    } else {
        for (int x : two) cout << x << " ";
        for (int x : neither) cout << x << " ";
        for (int x : three) cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}