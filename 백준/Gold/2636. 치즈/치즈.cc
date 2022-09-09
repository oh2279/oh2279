#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,cnt,cheese;
int board[101][101];
int dx[]={0,1,0,-1};
int dy[] = {1,0,-1,0};
queue<pair<int,int>> q;
queue<pair<int,int>> ch;
vector<int> v;
bool visited[101][101];

void bfs() {
    visited[0][0]=true;
    q.push({0,0});

    while(true) {
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    if (board[nx][ny] == 1) {
                        board[nx][ny]=0;
                        cheese++;
                        ch.push({nx,ny});
                    }
                    else if (board[nx][ny] == 0) {
                        q.push({nx, ny});
                    }
                    visited[nx][ny] = true;
                }
            }
        }
        if(cheese==0){
            int before =0;
            if(!v.empty()){
                before = v[v.size()-1];
            }
            cout << cnt<< '\n' << before;
            break;
        }
        else{
            v.push_back(cheese);
            cheese=0;
            while(!ch.empty()){
                q.push(ch.front());
                ch.pop();
            }
        }
        cnt++;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0; j<m;j++){
            cin >> board[i][j];
        }
    }
    bfs();
    return 0;
}