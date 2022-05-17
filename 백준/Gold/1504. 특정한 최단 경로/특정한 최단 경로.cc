#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int INF = 987654321;
int n, m,v1,v2;
int s,e, cost;
int dist[801];
vector<pair<int,int>> v[801];

void dijk(int start) {
	// memset(dist, 127, sizeof(dist)); // 127은 비트연산으로 약 21억 숫자
	// or
	fill(dist, dist + 801, 987654321);

	// 시작 노드 초기화
	dist[start] = 0;

	// (가중치, 도착노드)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int idx = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		// if (dist[idx] != cost) continue;

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
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> cost;
		v[s].push_back(make_pair(e, cost));
		v[e].push_back(make_pair(s, cost));
	}
	cin >> v1 >> v2;

	dijk(1); // 시작부터 끝까지의 최소비용
	// 1부터 v1 또는 v2까지의 값
	int sTov1 = dist[v1]; // s -> v1
	int sTov2 = dist[v2]; // s -> v2

	dijk(v1); // v1부터 끝까지
	int v1Tov2 = dist[v2]; // v1 -> v2
	int v1Toend = dist[n]; // v1 -> end

	dijk(v2); // v2부터 끝까지
	int v2Tov1 = dist[v1]; // v2 -> v1
	int v2Toend = dist[n]; // v2 -> end

	int sv1v2end = sTov1 + v1Tov2 + v2Toend; // s -> v1 -> v2 -> end
	int sv2v1end = sTov2 + v2Tov1 + v1Toend;// s -> v2 -> v1 -> end
	
	int result = INF;

	result = min(result, sv1v2end);
	result = min(result, sv2v1end);

	if (v1Tov2 == INF || result == INF) cout << -1;

	else cout << result;
	
	return 0;
}