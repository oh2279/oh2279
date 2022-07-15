#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <cstring>

using namespace std;

int map[101][101];
int visited[101][101];
int externAir[101][101];
queue<pair<int,int>> q;
int n,m,ans;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};


void bfs(int a, int b){
    q.push({a,b});
    map[a][b]=2;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(visited[x][y]) continue;
        visited[x][y] = true;
        map[x][y]=2;
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(map[nx][ny]==1) externAir[nx][ny]++;
                else if(!visited[nx][ny]){
                    q.push({nx,ny});
                }
            }
        }
    }
}
bool update(){
    bool flag = false;
    for(int i=0; i<n; i++) {
        for (int j = 0; j < m; j++) {
            if(externAir[i][j]>=2){
                map[i][j]=0;
                flag = true;
            }
        }
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    while(1) {
        memset(externAir,0,sizeof(externAir));
        memset(visited,0,sizeof(visited));
        bfs(0, 0);
        if (update()) {
            ans++;
        }
        else break;
    }
    cout << ans;
    return 0;
}