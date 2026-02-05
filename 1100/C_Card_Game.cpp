#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool beats(int n, int x, int y) {
    if (x == 0) {
        return y == n - 1;
    }
    if (x == n - 1) {
        return y != 0;
    }
    return x > y;
}

void solve() {
    int n;
    cin >> n;
    string owner;
    cin >> owner;

    bool good = false;

    for (int i = 0; i < n; ++i) {
        if (owner[i] != 'A') {
            continue;
        }

        bool good_move = true;

        for (int j = 0; j < n; ++j) {
            if (owner[j] == 'B' && beats(n, j, i)) {
                good_move = false;
                break;
            }
        }

        if (good_move) {
            good = true;
            break;
        }
    }

    if (good) {
        cout << "Alice" << "\n";
    } else {
        cout << "Bob" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}