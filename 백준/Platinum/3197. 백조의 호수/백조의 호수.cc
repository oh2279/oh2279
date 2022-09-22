#include <bits/stdc++.h>
#define ll long long
using namespace std;

int r,c,day=0;
char board[1501][1501];
bool visited[1501][1501];
int dx[]={0,1,0,-1};
int dy[] = {1,0,-1,0};

vector<pair<int,int>> L;
queue<pair<int,int>> wq;
queue<pair<int,int>> q;


void bfs(){
    q.push(L[0]);
    visited[L[0].first][L[0].second]=true;

    while(1){

        queue<pair<int,int>> nq;
        bool flag = false;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == L[1].first && y == L[1].second){
                flag = true;
                break;
            }

            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y + dy[i];

                if(nx <0 || nx >=r || ny <0 || ny >= c || visited[nx][ny]) continue;

                visited[nx][ny]=true;

                if(board[nx][ny]=='X'){
                    nq.push({nx,ny});
                }
                else q.push({nx,ny});

            }
        }
        if(flag) break;

        int siz = wq.size();
        while (siz--){
            int x = wq.front().first;
            int y = wq.front().second;
            wq.pop();

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx <0 || nx >=r || ny < 0 || ny >=c) continue;

                if(board[nx][ny]=='X'){
                    board[nx][ny]='.';
                    wq.push({nx,ny});
                }
            }
        }
        day++;

        while(!nq.empty()){
            q.push(nq.front());
            nq.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;

    for(int i=0; i<r;i++){
        string s;
        cin >> s;
        for(int j=0; j<c;j++){
            board[i][j] = s[j];
            if(board[i][j]=='L'){
                L.push_back({i, j});
            }
            if(board[i][j]=='.' || board[i][j]=='L'){
                wq.push({i,j});
            }
        }
    }
    bfs();

    cout << day;
    return 0;
}