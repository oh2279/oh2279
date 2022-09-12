#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,cnt,ans;
int board[101][101];
int dist[101][101];
bool visited[101][101];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void bfs(int a, int b){
    queue<pair<int,int>> q;
    dist[a][b]=cnt;
    q.push({a,b});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >=0 && ny < n && dist[nx][ny]==-1 && board[nx][ny]==1){
                q.push({nx,ny});
                dist[nx][ny]=cnt;
            }
        }
    }
}

void bfs2(int a, int b) {
    queue<pair<pair<int, int>, int>> q;
    memset(visited, false, sizeof(visited));
    q.push({{a, b}, 0});
    visited[a][b] = true;

    int number = dist[a][b];

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();

        if (dist[x][y] != number && board[x][y] == 1) {
            ans = min(ans, d - 1);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if((dist[nx][ny]!=number || dist[nx][ny]==-1) && !visited[nx][ny]){
                q.push({{nx,ny}, d+1});
                visited[nx][ny] = true;
            }
        }
    }
}

bool side(int a, int b){
    for(int i=0; i<4;i++){
        int nx = a + dx[i];
        int ny = b + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

        if(board[nx][ny]==0){
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    memset(dist, -1, sizeof(dist));

    cnt=1;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(board[i][j] == 1 && dist[i][j]==-1){
                bfs(i,j);
                cnt++;
            }
        }
    }

    ans = 987654321;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]==1 && side(i,j)){
                bfs2(i,j);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}