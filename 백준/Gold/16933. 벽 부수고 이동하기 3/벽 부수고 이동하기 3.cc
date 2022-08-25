#include <iostream>
#include <cstring>//scanf
#include <queue>
using namespace std;

struct State {
	int x, y;//xy좌표
	int b_cnt, p_len;//벽 부순 횟수, 이동한 거리
	int day;//1:낮, -1:밤
};

int N, M, K;
int Map[1000][1000];
bool visited[1000][1000][11];//x좌표, y좌표, 벽 부순 횟수
const int dxy[][2] = { {-1,0},{1,0},{0,-1},{0,1} };//상,하,좌,우

int bfs() {
	queue<State>q;
	q.push({ 0,0,0,1,1 });//좌표(0,0), 벽 0번 부숨, 이동한 거리 1, 낮
	visited[0][0][0] = true;
	int ans = -1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int b_cnt = q.front().b_cnt;
		int p_len = q.front().p_len;
		int day = q.front().day;
		q.pop();
		if (x == N - 1 && y == M - 1) {
			ans = p_len;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dxy[i][0];
			int ny = y + dxy[i][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			
			//다음 칸이 빈칸이고 아직 방문 안 했으면
			if (Map[nx][ny] == 0 && visited[nx][ny][b_cnt] == false) {
				visited[nx][ny][b_cnt] = true;
				q.push({ nx,ny,b_cnt,p_len + 1,-day });
			}
			//다음 칸이 벽이고 아직 벽을 부술 수 있고 b_cnt만큼 벽을 부수고 방문한 적이 없다면
			if (Map[nx][ny] == 1 && b_cnt < K && visited[nx][ny][b_cnt + 1] == false) {
				//낮이면 벽부수고 이동
				if (day == 1) {
					visited[nx][ny][b_cnt + 1] = true;
					q.push({ nx,ny,b_cnt + 1,p_len + 1,-day });
				}
				//밤이면 같은 자리에서 대기, 이동 거리만 +1
				else if (day == -1) {
					q.push({ x,y,b_cnt,p_len + 1,-day });
				}
			}
			
		}
	}
	return ans;
}

void solution() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &Map[i][j]);
		}
	}
	int ans = bfs();
	cout << ans << '\n';
}

int main() {
	solution();
	return 0;
}