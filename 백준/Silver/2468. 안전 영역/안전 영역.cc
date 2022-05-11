#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, cnt;
// vector<int> v[1001];
vector<int> v;
int board[101][101];
int visited[101][101];
queue<pair<int,int>> q;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

/*void dfs(int idx) {
	cout << idx << " ";
	visited[idx] = true;
	for (int i = 0; i< v[idx].size(); i++) {
		int next = v[idx][i];
		if (visited[next] == false) {
			dfs(next);
		}
	}
}*/

void bfs(int rain) {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (board[nx][ny] > rain && visited[nx][ny] == 0) {
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int ans = - 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
			board[i][j]=tmp;
		}
	}
	sort(v.begin(), v.end());

	// 안전지대가 없는 곳 예외처리
	if (v.front() == v.back()) {
		cout << 1;
		return 0;
	}
	for (int i = v.front(); i <= v.back(); i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				visited[j][k] = 0;
			}
		}
		cnt = 1; // 섬의 개수
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (board[j][k] > i && visited[j][k] == 0) {
					q.push(make_pair(j,k));
					visited[j][k] = 1;
					bfs(i);
					cnt++;
					
				}
			}
		}
		ans < cnt ? ans = cnt : ans;
	}
	cout << ans-1;
	return 0;
}