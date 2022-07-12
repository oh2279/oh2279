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
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (visited[y][x] == k+1 ) continue;
        for(int i=0; i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || map[ny][nx]==4) continue;
            visited[ny][nx] = visited[y][x] + 1;
            map[ny][nx] = 1;
            q.push({ ny, nx });
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
    nq.push({sy, sx});
    visited[sy][sx]=1;
    while(!nq.empty()){
        int y = nq.front().first;
        int x = nq.front().second;
        nq.pop();

        for(int i=0; i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || map[ny][nx]==1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            if (map[ny][nx] == 2) return visited[y][x];
            nq.push({ny, nx });
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
                sy=i; sx=j;
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