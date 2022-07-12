#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <cstring>

using namespace std;

int map[2001][2001];
int visited[2001][2001];
queue<pair<int,int>> q;
int dx[]={1,0,-1,0};
int dy[] = {0,1,0,-1};
int n,m,k;
int sx,sy;

void bfs_for_three(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (visited[x][y] == k+1 ) continue;
        for(int i=0; i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[nx][ny] || map[nx][ny]==4) continue;
            visited[nx][ny] = visited[x][y] + 1;
            map[nx][ny] = 1;
            q.push({ nx, ny });
        }
    }
}
void reset(){
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            visited[i][j]=0;
        }
    }
}

int bfs(){
    queue<pair<int,int>> nq;
    nq.push({sx, sy});
    visited[sx][sy]=1;
    while(!nq.empty()){
        int x = nq.front().first;
        int y = nq.front().second;
        nq.pop();

        for(int i=0; i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[nx][ny] || map[nx][ny]==1) continue;
            visited[nx][ny] = visited[x][y] + 1;
            if (map[nx][ny] == 2) return visited[x][y];
            nq.push({nx, ny });
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> map[i][j];
            if(map[i][j]==4){
                sx=i; sy=j;
            }
        }
    }
    for(int i=0; i<n;i++) {
        for (int j = 0; j < m; j++) {
            if(map[i][j]==3){
                map[i][j]=1;
                visited[i][j]=1;
                q.push({i,j});
            }
        }
    }
    bfs_for_three();
    reset();
    cout << bfs();

    return 0;
}