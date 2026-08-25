#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long  n , b;
    cin>>n >> b;
    vector<long long > a(n);
    long long  sum =0;
    for(long long  i =0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    sort(a.begin(),a.end());
    long long  ans = 0;
    long long  j = n-1, day =0;
    while(j>=0){
        while(sum + (j+1) * day > b){
            sum -= a[j];
            j--;   
        }
        ans+= (j+1);
        day++;
    }
    cout<< ans << endl;
}

int main (){
    long long  t;
    cin>> t;
    while(t--){
        solve();
    }
}