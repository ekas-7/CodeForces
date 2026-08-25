#include<bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};

void solve(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    int n;
    cin>>n;
    while(n--){
        int i =0 ;;
        int l;
        cin >> l;
        
        int maxi = INT_MIN;
        while(i!=l){
            int x;
            cin >> x;
            maxi = max(maxi, x -i);
            i++;
        }
        pq.push({maxi, l});
    }   

    int ans = pq.top().first + 1 ;
    int offset = pq.top().second;
    pq.pop();  

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int maxi = p.first;
        int l = p.second;

        if(ans+offset > maxi){
           offset += l;
           continue;
        }
        else{
            ans += maxi + 1 - (ans + offset);
            offset += l;
        }
    }
    cout<<ans <<"\n";
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