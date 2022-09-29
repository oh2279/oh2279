#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int N,L,R;
int board[51][51];
queue<pair<int,int>> q;
vector<pair<int,int>> v;
bool visited[51][51];
int sum =0;

void bfs(int r,int c) {
    q.push({r,c});
    visited[r][c] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;

            int diff = abs(board[x][y] - board[nx][ny]);
            if (L <= diff && diff <= R) {
                v.push_back({nx,ny});
                sum += board[nx][ny];
                q.push({nx,ny});
                visited[nx][ny]=true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> N >> L >> R;

    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            cin >> board[i][j];
        }
    }
    int ans=0;
    bool flag = true;
    while(flag){
        flag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    v.clear();
                    v.push_back({ i,j });
                    sum = board[i][j];
                    bfs(i,j);
                }
                if (v.size() >= 2) {
                    flag = true; //연합 체크
                    for (int k= 0; k < v.size(); k++) {
                        int r = v[k].first;
                        int c = v[k].second;
                        int cnt = v.size();
                        board[r][c] = sum / cnt; //평균 갱신
                    }
                }
            }
        }
        if (flag) ans++;

        memset(visited,false,sizeof(visited));
    }
    cout << ans;
    return 0;
}