#include<iostream>


using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

void solve(){
    string p,s;
    cin>>p>>s;
    int n = p.size();
    int m = s.size();
    int i = 0, j = 0;
    bool possible = true;
    while(i < n && j < m){
        int conti =1;
        while(i+1 < n && p[i] == p[i+1]){
            conti++;
            i++;
        }
        int contj = 1;
        while(j+1 < m && s[j] == s[j+1]){
            contj++;
            j++;
        }
        if(p[i] != s[j] || 2* conti <contj || conti > contj){
            possible = false;
            break;
        }
        i++;
        j++;
    }
    if(i != n || j != m){
        possible = false;
    }
    if(possible){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}