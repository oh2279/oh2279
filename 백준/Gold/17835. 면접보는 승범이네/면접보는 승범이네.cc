#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define INF 1e18
using namespace std;
typedef long long ll;

ll n, m, k, u, v, c;
ll len = -1, num = 0;
ll dist[100001];
vector<ll> meet;
vector<pair<ll, ll>> arr[100001];

void dijk() {

	// fill(dist, dist + 100001, INF);

	// (가중치, 도착노드)
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

	// 시작 노드 초기화
	for (auto &w : meet) {
		pq.push({ 0LL, w });
		dist[w] = 0LL;
	}
	
	while (!pq.empty()) {
		ll idx = pq.top().second; // 도착노드
		ll cost = pq.top().first; // cost
		pq.pop();

		if (dist[idx] < cost) continue;

		for (int i = 0; i < arr[idx].size(); i++) {
			ll next = arr[idx][i].first; // 연결된 다음 노드
			ll weight = arr[idx][i].second; //가중치

			if (dist[next] > dist[idx] + weight) { // 더 작은 cost가 존재한다면
				// if u -> v , dist[v] < dist[u] + w(u,v)이면 초기화할 필요 x
				dist[next] = dist[idx] + weight;
				pq.push({ dist[next],next });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (len < dist[i]) {
			num = i;
			len = dist[i];
		}
	}
	cout << num << "\n" << len << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		arr[v].push_back({ u,c });
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	for (int i = 0; i < k; i++) {
		ll meeting;
		cin >> meeting;
		meet.push_back(meeting);
	}
	dijk();

	return 0;
}