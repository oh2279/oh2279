#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int INF = 987654321;
int n,cost;
int dist[130][130];
int map[130][130];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dijk() {
	// memset(dist, 127, sizeof(dist)); // 127은 비트연산으로 약 21억 숫자
	// or
	// fill(dist, dist + 130, INF);

	// 시작 노드 초기화
	dist[0][0] = map[0][0];

	// (가중치, 도착노드)
	priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	pq.push(make_pair(map[0][0], make_pair(0, 0)));
	
	while (!pq.empty()) {
		int x = pq.top().second.first; // 도착노드의 x좌표
		int y = pq.top().second.second; // 도착노드의 y좌표
		pq.pop();

		// if (dist[idx] != cost) continue;

		for (int i = 0; i <4; i++) { // 상하좌우 탐색
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ncost = map[ny][nx];

			if (0<=nx && nx < n && 0 <= ny && ny < n) { // 범위 안에서
				if (dist[nx][ny] > dist[x][y] + ncost) { // 더 작은 cost가 존재한다면
					// if u -> v , dist[v] < dist[u] + w(u,v)이면 초기화할 필요 x
					dist[nx][ny] = dist[x][y] + ncost;
					pq.push(make_pair(dist[x][y] + ncost, make_pair(nx, ny)));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;

	while (1) {
		cin >> n;
		if (n == 0)break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> cost;
				map[i][j] = cost;
				dist[i][j] = INF;
			}
		}
		dijk();
		cnt++;
		cout << "Problem " << cnt << ": " << dist[n - 1][n - 1] << "\n";
	}
	
	return 0;
}