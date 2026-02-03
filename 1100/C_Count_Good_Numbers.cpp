#include<iostream>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

ll count(ll N){
    ll count2 = N/2 , count3 = N/3 , count5 = N/5 , count7 = N/7;
    ll count6 = N/6 , count10 = N/10 , count14 = N/14 , count15 = N/15 , count21 = N/21 , count35 = N/35;
    ll count30 = N/30 , count42 = N/42 , count70 = N/70 , count105 = N/105;
    ll count210 = N/210;    
    ll goodNumbers = (count2 + count3 + count5 + count7) 
                    - (count6 + count10 + count14 + count15 + count21 + count35) 
                    + (count30 + count42 + count70 + count105) 
                    - (count210);
    return goodNumbers;
}

void solve(){
    ll L, R;
    cin >> L >> R;

    cout << (R-L+1)-(count(R) - count(L-1)) << endl;
}

int main() {
    int T =1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}