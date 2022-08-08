#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <string>
#include <queue>
#include <functional>
#include <complex>
#include <cmath>
#include <unordered_map>
#include <map>
typedef long long ll;
using namespace std;

int n, m,s,e,c,start_city,end_city;
int dist[1001];
int route[1001];
stack<int> ans;
vector<pair<int,int>> v[1001]; // {도착, 비용}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq; // {도착 도시, 비용}

void dijk(){
    memset(dist,127,sizeof(dist));

    dist[start_city]=0;
    route[1]=0;
    pq.push({start_city,0});

    while(!pq.empty()){
        int now = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if(dist[now]!=cost) continue;

        for(int i=0; i<v[now].size();i++){
            int next = v[now][i].first;
            int w = v[now][i].second;

            if(dist[next] > dist[now] + w){
                dist[next]=dist[now]+w;
                route[next]=now; // next로 가기 위해선 now를 거쳐야 함을 저장
                pq.push({next, dist[next]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<m;i++){
        cin >> s >> e >> c;
        v[s].push_back({e,c});
    }
    cin >> start_city >> end_city;

    dijk();
    cout << dist[end_city] << '\n';

    while(end_city!=0){
        ans.push(end_city);
        end_city = route[end_city];
    }
    cout << ans.size() << '\n';

    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }
}
