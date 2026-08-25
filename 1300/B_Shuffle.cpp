#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n , x , m;
    cin >> n >> x >> m;
    bool found = false;

    long long lans = -1 , rans = -1;
    
    while(m--){
        long long l , r;
        cin >> l >> r;
        if(l <= x && x <= r){
            found = true;
        }
        if(found){
           lans = l ;
           rans = r ;
           break;
        }
    }
    
    if(!found){
        cout << 1 << endl;
        return;
    }

    while (m--)
    {
        long long l , r;
        cin >> l >> r;
        if(l <= rans && r >= lans){
            lans = min(lans , l);
            rans = max(rans , r);
        }
    }

    cout << rans - lans + 1 << endl;

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