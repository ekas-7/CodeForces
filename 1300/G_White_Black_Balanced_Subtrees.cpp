#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        char color;
        vector<Node*> children;
    
    Node(char c){
        color = c;
    }
}; 

pair<int,int> helper(Node* node, long long &ans){
    if(node == nullptr){
        return {0, 0};
    }

    pair<int,int> counts = {0, 0};
    for(auto child : node->children){
        pair<int,int> child_counts = helper(child, ans);
        counts.first += child_counts.first;
        counts.second += child_counts.second;
    }

    if(node->color == 'W'){
        counts.first++;
    }else{
        counts.second++;
    }

    if(counts.first == counts.second){
        ans++;
    }

    return counts;

    
}

void solve(){
    long long n;
    cin >> n;
    
    vector<long long> a(n + 1);
    for(long long i = 2; i <= n; i++){
        cin >> a[i];  
    }
    
    string s;
    cin >> s;
    
    vector<Node*> nodes(n + 1);
    for(long long i = 1; i <= n; i++){
        nodes[i] = new Node(s[i - 1]);
    }
    
    for(long long i = 2; i <= n; i++){
        nodes[a[i]]->children.push_back(nodes[i]);
    }

    long long ans = 0;

    helper(nodes[1], ans);

    cout << ans << "\n";
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