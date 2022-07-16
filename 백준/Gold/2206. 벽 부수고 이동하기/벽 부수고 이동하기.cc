#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

int map[1001][1001];
int visited[1001][1001][2];
// 1은 벽 안부순거, 0은 부순거
queue<pair<pair<int,int>,int>> q;
string str;
int n,m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int bfs(){
    q.push({{1,1},1});
    visited[1][1][1]=1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second;
        q.pop();

        if(x==n && y==m) return visited[x][y][wall];

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <=m) {
                if(wall == 1 && map[nx][ny]==1){ // 벽인데 뚫을 수 있는 상태
                    q.push({{nx,ny},0});
                    visited[nx][ny][0] = visited[x][y][1] + 1;
                }
                else if(map[nx][ny]==0 && visited[nx][ny][wall]==0){
                    q.push({{nx,ny},wall});
                    visited[nx][ny][wall] = visited[x][y][wall] + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i=1; i<=n;i++){
        cin >> str;
        for(int j=1; j<=str.size();j++){
            map[i][j] = str[j-1]-48;
        }
    }
    int ans = bfs();

    cout << ans;
    return 0;
}