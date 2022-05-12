#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int board[8][8];
int board2[8][8];
int board3[8][8];
bool check[8][8];
int ans = 0;
int n, m;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>>q;


void mapCopy(int(*a)[8], int(*b)[8]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = b[i][j];
}

void bfs() {

	mapCopy(board3, board2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board3[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (board3[nx][ny] == 0 ) {
					board3[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
		
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board3[i][j] == 0)
				cnt += 1;
		}
	}
	ans = max(ans, cnt);
}

void wall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	//벽을 세움
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board2[i][j] == 0) {
				board2[i][j] = 1;
				wall(cnt + 1);
				board2[i][j] = 0;
			}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			board[i][j] = tmp;
		}
	}

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			if (board[r][c] == 0 ) {
				mapCopy(board2, board);
				board2[r][c] = 1;
				wall(1);
				board2[r][c] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}