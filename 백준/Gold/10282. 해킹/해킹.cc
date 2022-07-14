#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <cstring>

using namespace std;
vector<pair<int,int>> v[10001];
int dist[10001];

int n,d,c,t,a,b,s;

void dijk(int start){
    fill(dist,dist+10001,987654321);
    dist[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        int time = pq.top().first;
        int pollution = pq.top().second;
        pq.pop();
        if(dist[pollution] < time) continue;

        for(int i=0; i<v[pollution].size();i++){
            int next = v[pollution][i].first;
            int ptime = v[pollution][i].second;
            int total = ptime + time;
            if (total < dist[next]) {
                dist[next] = total;
                pq.push({ total, next });
            }
        }
    }
    int count=0,ans=0;
    for(int i=0; i<10001;i++){
        if(dist[i]==987654321) continue;
        count++;
        // cout <<"dist[" << i  << "]: " <<dist[i] << '\n';
        ans = max(ans, dist[i]);
    }
    cout << count << ' ' << ans <<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    for(int j=0; j<t; j++) {
        cin >> n >> d >> c;
        for (int i = 0; i < d; i++) {
            cin >> a>>b>>s;
            v[b].push_back({a,s});
        }
        dijk(c);
        memset(v, 0, sizeof(v));
    }
    return 0;
}