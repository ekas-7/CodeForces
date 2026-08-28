#include<bits/stdc++.h>
using namespace std;

bool is_feasible(long long  mid , vector<long long > &eff_task , long long  tasks){
    vector<long long >eff_left(eff_task.size()+1 , 0);
    vector<long long >slot_left(eff_task.size()+1 , 0);
    for(long long  i=1; i<eff_task.size(); i++){
        eff_left[i] = eff_task[i] - mid ;
        slot_left[i] = mid - eff_task[i];
        if(eff_left[i] < 0) eff_left[i] = 0;
        if(slot_left[i] < 0) slot_left[i] = 0;
    }
    long long  total_eff_left = 0 ;
    for(long long  i=1; i<eff_task.size(); i++){
        total_eff_left += eff_left[i];
        total_eff_left -= slot_left[i] / 2;
    }
    return total_eff_left <= 0;
}

void solve(){
    long long  workers , tasks;
    cin >> workers >> tasks;
    vector<long long > eff_worker(tasks);
    vector<long long > eff_task(workers + 1 , 0);
    for(long long  i=0; i<tasks; i++){
        cin >> eff_worker[i];
        eff_task[eff_worker[i]]++;
    }

    long long  low = 1 , high = 2 * tasks;
    long long  ans = -1 ;
    while(low < high){
        long long  mid = (low + high) / 2;
        if(is_feasible(mid , eff_task , tasks)){
            high = mid;
            ans = mid;
        }else{
            low = mid + 1;
        }
    }

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long  t;
    if(cin >> t){
        while(t--){
            solve();
        }
    }
    return 0;

}