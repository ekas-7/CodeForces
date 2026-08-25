#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int zeros=0;

    for(auto it:s){
        if(it=='0')zeros++;
    }
    if(zeros==1){
        cout<<"BOB\n";
        return;
    }

    if(zeros % 2 ==0){
        if(zeros%4==0){
            cout<<"DRAW\n";
        }
        else{
            cout<<"BOB\n";
        }
    }
    else{
        if(zeros%4==1){
            cout<<"DRAW\n";
        }
        else{
            cout<<"ALICE\n";
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}