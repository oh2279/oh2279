#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>

using namespace std;

int n,level=2,exp,cnt,sec,ans;
int a,b,c,d;
int map[21][21];
int dist[21][21];
queue<pair<int,int>> q;
bool visited[21][21];

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

bool bfs(){

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(map[x][y] !=9 && map[x][y] !=0  && map[x][y] < level)continue;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(ny>=0 && ny<n && nx>=0 && nx<n && dist[nx][ny]==-1 &&map[nx][ny]<= level ){
                dist[nx][ny] = dist[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    // find minimum y, x, dist
    int my = 100;
    int mx = 100;
    int m_dist = 401;
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(map[i][j]!=0 && map[i][j] !=9&& map[i][j]<level && dist[i][j] != -1 && dist[i][j]<=m_dist){
                m_dist = dist[i][j];
                mx = i;
                my = j;
            }
        }
    }
    if(m_dist == 401){
        return false;
    }else{
        map[a][b] =0;
        a = mx;
        b = my;
        exp++;
        if(level == exp){
            exp=0;
            level++;
        }
        map[mx][my] = 9;
        ans+= dist[mx][my];
        return true;
    }
}

void go(int a, int b, int c, int d){
    int sx = abs(a-c);
    int sy = abs(b-d);

    cout << sx + sy;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j]==9) {
                a=i;
                b=j;
            }
            else if(map[i][j] >=1 && map[i][j] <=6){
                cnt++;
                if(cnt==1){
                    c=i+1; d=j+1;
                }
            }
        }
    }
    if(cnt==1) go(a+1,b+1,c,d);
    else {
        while (true) {
            memset(dist, -1, sizeof(dist));
            dist[a][b] = 0;
            q.push({a, b});
            if (bfs()) {
                continue;
            } else break;
        }
        cout << ans;
    }
    return 0;
}