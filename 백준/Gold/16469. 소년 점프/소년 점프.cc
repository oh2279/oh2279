#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int r, c, xi,yi;
char map[101][101];
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
int dist[101][101][3];
int visited[101][101][3];
queue<pair<pair<int,int>,int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int num = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < r && 0 <= ny && ny < c) {
				if (dist[nx][ny][num] == -1 && map[nx][ny]=='0') { // 방문하지 않았다면,
					dist[nx][ny][num] = dist[x][y][num]+1;
					q.push({ {nx,ny }, num});
				}
			}
			else {
				continue;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(visited, 0, sizeof(visited));
	memset(dist, -1, sizeof(dist));

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> map[i];
	}
	for (int i = 0; i <= 2; i++) {
		cin >> xi >> yi;
		q.push({{ xi - 1,yi - 1 }, i});
		dist[xi - 1][yi - 1][i]=0;
	}
	bfs();

	int ans = 987654321, cnt = 0;;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int a = dist[i][j][0], b = dist[i][j][1], c = dist[i][j][2];
			int maxi = max(a,max(b,c));
			if (min(min(a, b), c) != -1) {
				if (ans > maxi) {
					ans = maxi;
					cnt = 1;
				}
				else if (ans == maxi) {
					cnt++;
				}
			}
		}
	}
	if (cnt) {
		cout << ans << "\n" << cnt;
	}
	else {
		cout << -1;
	}
	return 0;
}