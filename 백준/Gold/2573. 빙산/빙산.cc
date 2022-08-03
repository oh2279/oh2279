#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

int n,m;
int map[301][301];
int map2[301][301];
bool visited[301][301];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void bfs(int r, int c){
    queue<pair<int,int>> q;
    q.push({r,c});

    while(!q.empty()){
        int x = q.front().first;
        int y= q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >=0 && ny < m && map[nx][ny] != 0 && !visited[nx][ny]){
                q.push({ nx,ny });
                visited[nx][ny] = true;
            }
        }
    }
}

// 내 주변의 물 세기
void melting(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) continue;
            int waterCnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (map[nx][ny] == 0) {
                    waterCnt++;
                }
            }
            int val = map[i][j] - waterCnt;
            if (val > 0) map2[i][j] = val;
            else if(val <= 0 ) map2[i][j]=0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] = map2[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> map[i][j];
        }
    }
    int ans = 0;
    while(true){
        memset(visited, false, sizeof(visited));
        memset(map2,0,sizeof(map2));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && map[i][j] != 0) {
                    bfs(i, j);
                    cnt++; // bfs 한번 = 한 덩이
                }
            }
        }
        if (cnt == 0) {
            cout << 0;
            break;
        }
        else if (cnt >= 2) {
            cout << ans;
            break;
        }
        ans++; // 1초 증가

        melting();
    };
    return 0;
}