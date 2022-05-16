#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
int s,e, cost;
int dist[1010];
vector<pair<int,int>> v[1010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> cost;
		v[s].push_back(make_pair(e, cost));
	}
	cin >> s >> e;
	memset(dist, 127, sizeof(dist)); // 127은 비트연산으로 약 21억 숫자
	// or
	// fill(dist, dist + 1010, 987654321);

	// 시작 노드 초기화
	dist[s] = 0;

	// (가중치, 도착노드)
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({ 0,s });

	while (!pq.empty()) {
		int idx = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[idx] != cost) continue;

		for (int i = 0; i < v[idx].size(); i++) {
			int next = v[idx][i].first;
			int weight = v[idx][i].second;

			if (dist[next] > dist[idx] + weight) {
				// if u -> v , dist[v] < dist[u] + w(u,v)이면 초기화할 필요 x
				dist[next] = dist[idx] + weight;
				pq.push({ dist[next],next });
			}
		}
	}
	cout << dist[e] << "\n";
	return 0;
}