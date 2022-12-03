#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 2e9

int n, m;
int b,e,s, a,t,cost;
int dist[100001];
vector<pair<int,int>> v[100001];

int dijk(int start, int end,int dont){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //memset(dist, 127, sizeof(dist)); // 127은 비트연산으로 약 21억 숫자
    // or
    fill(dist, dist + 100001, INF);

    // 시작 노드 초기화
    dist[start] = 0;

    // (가중치, 도착노드)
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if (dist[idx] < cost) continue;

        for (int i = 0; i < v[idx].size(); i++) {
            int next = v[idx][i].first;
            int weight = v[idx][i].second;

            if (dist[next] > dist[idx] + weight) {
                // if u -> v , dist[v] < dist[u] + w(u,v)이면 초기화할 필요 x
                if(next==dont) continue;
                dist[next] = dist[idx] + weight;
                pq.push({dist[next], next});
            }
        }
    }
    return dist[end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> b >> e >> cost;
        v[b].push_back({e, cost});
    }
    cin >> s >> a >> t;
    int firstHalf = dijk(s,a,0);
    int secondHalf = dijk(a,t,0);
    int nomiddle = dijk(s,t,a);
    cout << (firstHalf == INF || secondHalf == INF ? -1 : firstHalf + secondHalf) << " ";
    cout << (nomiddle == INF ? -1 : nomiddle);
    return 0;
}