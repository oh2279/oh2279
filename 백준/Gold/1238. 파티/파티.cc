#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int INF = 987654321;
int n, m,x;
int s,e, cost;
int dist[1010],ans[1010];
vector<pair<int,int>> v[1010];

void dijk(int start) {
	// memset(dist, 127, sizeof(dist)); // 127은 비트연산으로 약 21억 숫자
	// or
	fill(dist, dist + 1010, INF);

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

	int res = 0;

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> cost;
		v[s].push_back(make_pair(e, cost));
	}

	dijk(x); // x번 마을에서 모인 학생들이 집으로 가는데 필요한 최소비용 검사
	for (int i = 1; i <= n; i++) {
		
		ans[i] += dist[i]; // 1번 학생부터 
	}

	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		dijk(i); // 1번 학생부터 조사
		ans[i] += dist[x]; // x번 마을까지 가는데 필요한 최소비용
		res = max(res, ans[i]);
	}

	cout << res;
	return 0;
}