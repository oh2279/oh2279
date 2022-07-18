#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;
int n,m,ans,res=987654321,empty_place,infect;
int map[51][51];
int visited[51][51];
bool selected[10];
int dx[]={1,0,-1,0};
int dy[] = {0,1,0,-1};

vector<pair<int,int>> v;

void bfs(queue<pair<int,int>> Q) {
    infect=0;
    ans=0;
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >=0 && ny < n) {
                if (map[nx][ny] != 1 && visited[nx][ny] == -1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    if (map[nx][ny] == 0) {
                        infect++;
                        ans = visited[nx][ny];
                    }
                    Q.push({nx, ny});
                }
            }
        }
    }
    if(empty_place == infect){
        res = min(res, ans);
    }
}
void select(int idx, int cnt){
    if(cnt == m){
        queue<pair<int,int>> q;
        memset(visited,-1,sizeof(visited));

        for(int i=0; i<v.size();i++){
            if(selected[i]){
                q.push({v[i].first,v[i].second});
                visited[v[i].first][v[i].second]=0;
            }
        }
        bfs(q);
        return;
    }
    for(int i=idx; i<v.size();i++){
        if(selected[i])continue;
        selected[i]=true;
        select(i+1,cnt+1);
        selected[i]=false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2){
                v.push_back({i,j});
            }
            else if(map[i][j]==0){
                empty_place++;
            }
        }
    }
    memset(selected,false,sizeof(selected));
    select(0,0);
    if(res == 987654321) res=-1;
    cout << res;
}