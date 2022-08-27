#include <bits/stdc++.h>

using namespace std;

int r,c,sx,sy;
string s;
char board[51][51];
int dx[] ={-1,0,1,0};
int dy[] = {0,1,0,-1};

queue<pair<int,int>> water;
bool flood[51][51];
bool visited[51][51];
int dist[51][51];

void bfs_water(){
    int siz = water.size();
    while(siz--){
        int x = water.front().first;
        int y = water.front().second;
        water.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <0 || nx >= r || ny < 0 ||ny >= c) continue;
            if(board[nx][ny]=='D' || board[nx][ny] == 'X' || flood[nx][ny]) continue;
            water.push({nx,ny});
            board[nx][ny] = '*';
            flood[nx][ny] = true;
        }
    }
}

void bfs(){
    queue<pair<int,int>> q;
    q.push({sx,sy});
    visited[sx][sy]=true;

    while(!q.empty()){
        bfs_water();
        int siz = q.size();
        while(siz--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();


            if (board[x][y] == 'D') {
                cout << dist[x][y];
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (visited[nx][ny] || board[nx][ny] == '*' || board[nx][ny] == 'X') continue;

                q.push({nx, ny});
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    cout << "KAKTUS";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;

    for(int i=0; i<r; i++){
        cin >> s;
        for(int j=0; j<s.size();j++){
            board[i][j]=s[j];
            if(board[i][j]=='S'){
                sx = i;
                sy = j;
            }
            else if(board[i][j]=='*'){
                water.push({i,j});
                flood[i][j]=true;
            }
        }
    }
    bfs();
}