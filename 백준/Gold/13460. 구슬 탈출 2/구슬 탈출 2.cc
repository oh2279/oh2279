#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

struct state{
    int rx,ry;
    int bx,by;
    int d;
};
char map[10][10];
bool visited[10][10][10][10];
int n,m;
string str;
queue<state> q;

int dx[]={1,0,-1,0};
int dy[] = {0,1,0,-1};

void bfs(){
    while(!q.empty()) {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int d = q.front().d;
        q.pop();

        if(d>=10) break;

        for (int i = 0; i < 4; i++) {
            int nrx = rx, nry = ry;
            int nbx = bx, nby = by;
            int rc=0, bc=0,nd = d+1;

            // 범위 안에 들고, 벽이 아닌 경우
            while (map[nrx+dx[i]][nry+dy[i]] != '#' && map[nrx][nry] != 'O') {
                nrx += dx[i];
                nry += dy[i];
                rc++;
            }
            while (map[nbx+dx[i]][nby+dy[i]] != '#' && map[nbx][nby] != 'O') {
                nbx += dx[i];
                nby += dy[i];
                bc++;
            }
            // 파란 구슬이 구멍에 빠지면 다른 방향 탐색
            if(map[nbx][nby]=='O') continue;

            if(map[nrx][nry]=='O') {
                cout << nd;
                return;
            }

            // 겹치면 더 뒤에서 출발한 구슬이 한칸 뒤로 무름
            if(nrx==nbx && nry == nby){
                if(rc > bc) nrx-= dx[i], nry -=dy[i];
                else nbx -= dx[i], nby -=dy[i];
            }
            if(visited[nrx][nry][nbx][nby]) continue;
            visited[nrx][nry][nbx][nby] = true;
            q.push({nrx,nry,nbx,nby,nd});
        }
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    int rx=0,ry=0,bx=0,by=0;

    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<m;j++){
            map[i][j] = str[j];
            if(map[i][j] == 'R' ){
                rx = i;
                ry = j;
            }
            else if (map[i][j]=='B'){
                bx = i;
                by = j;
            }
        }
    }
    q.push({rx,ry,bx,by,0});
    visited[rx][ry][bx][by]=true;
    bfs();
}