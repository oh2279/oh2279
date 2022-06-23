#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int m, n, cnt;
int box[1001][1001];
int dx[] = {0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (box[nx][ny] == 0 && nx >= 0 && nx < m && ny >= 0 && ny < n) {
				box[nx][ny] = box[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int ans=987654321;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) { 
				q.push({ i, j });
			}
		}
	}
	
	bfs();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (cnt < box[i][j]) {
				cnt = box[i][j];
			}
		}
	}
	cout << cnt - 1;

	return 0;
}