#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

bool selected[10];
int map[51][51];
int visited[51][51];
int n,m,res,ans=987654321,empty_place;
int dx[]={1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<pair<int,int>> v;

void bfs(queue<pair<int,int>> Q) {
    int infect=0;
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >=n || ny < 0 || ny >= n) continue;

            if(map[nx][ny] != 1 && visited[nx][ny]==-1) {
                visited[nx][ny] = visited[x][y] + 1;
                res = visited[nx][ny];
                Q.push({nx, ny});
                infect++;
            }
        }
    }
    if(infect == empty_place) ans = min(ans, res);
}

void select_virus(int idx, int cnt){
    if(cnt == m){
        queue<pair<int,int>> q;
        memset(visited,-1,sizeof(visited));
        for(int i=0; i<v.size();i++){
            if(selected[i]) {
                q.push({v[i].first, v[i].second});
                visited[v[i].first][v[i].second]=0;
            }
        }
        bfs(q);
        return;
    }
    for(int i=idx; i<v.size();i++){
        if(selected[i])continue;
        selected[i] = true;
        select_virus(i+1,cnt+1);
        selected[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            cin >> map[i][j];
            if(map[i][j] != 1) empty_place++;
            if(map[i][j]==2){
                v.push_back({i,j});
            }
        }
    }
    empty_place = empty_place - m;
    select_virus(0,0);
    if(ans == 987654321) ans = -1;
    cout <<ans;
}