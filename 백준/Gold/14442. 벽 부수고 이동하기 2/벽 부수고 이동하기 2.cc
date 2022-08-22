#include <bits/stdc++.h>

using namespace std;

int n,m,k;
string s;
int board[1001][1001];
bool visited[1001][1001][11];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};;

struct P{
    int r, c;       // 현재 위치
    int cnt = 1;    // 지금까지 지나온 칸 수
    int wall = 0;   // 지금까지 부순 벽의 수
};

int bfs(){
    // x,y좌표 + 지나온 칸의 수,벽을 부순 횟수
    queue<P> q;
    P tmp;
    tmp.r = 0; tmp.c=0;
    q.push(tmp);
    visited[0][0][0] = true;

    while(!q.empty()){
        int x = q.front().r;
        int y = q.front().c;
        int ans = q.front().cnt;
        int wall = q.front().wall;
        q.pop();

        if(x==n-1 && y == m-1) return ans;

        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 이미 방문한 경우
            if (visited[nx][ny][wall]) continue;
            if (board[nx][ny] == 0) {
                q.push({nx,ny,ans+1,wall});
                visited[nx][ny][wall] = true;
            } else if (board[nx][ny] == 1) { // 벽을 만난 경우
                if (wall < k) { // 부술 수 있다면
                    if(visited[nx][ny][wall+1]) continue;
                    q.push({nx,ny,ans+1,wall+1});
                    visited[nx][ny][wall+1] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0; j<m;j++){
            board[i][j] = s[j]-'0';
        }
    }
    cout << bfs();
}