#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,a,b;
int dist, fuel;

vector<pair<int,int>> v;
priority_queue<int> pq;

bool cmp(pair<int,int> a, pair<int, int> b){
    if(a.first==b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i=0; i<n;i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);

    cin >> dist >> fuel;

    int ans=0,idx=0;
    for(int i=1; i<dist;i++){
        fuel--;
        if(v[idx].first==i){
            pq.push(v[idx].second);
            idx++;
        }
        if(fuel<=0){
            if(!pq.empty()) {
                fuel = pq.top();
                pq.pop();
                ans++;
            }
            else{
                ans = -1;
                break;
            }
        }
    }

    cout << ans;
    return 0;
}