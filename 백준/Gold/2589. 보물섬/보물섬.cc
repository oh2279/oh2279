#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
string s;
char board[51][51];
bool visited[51][51];
int arr[51][51],maxi;
queue<pair<int,int>> q;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void reset(){
    memset(arr,0,sizeof(arr));
    memset(visited,false,sizeof(visited));
}

int bfs(int a, int b){
    q.push({a,b});
    arr[a][b]=0;
    visited[a][b]=true;

    while(!q.empty()){
        int x = q.front().first;
        int y  =q.front().second;
        q.pop();

        for(int i=0; i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny]=='W' || visited[nx][ny]) continue;

            visited[nx][ny]=true;
            arr[nx][ny] = arr[x][y]+1;
            q.push({nx,ny});
            if(maxi < arr[nx][ny]) {
                maxi = arr[nx][ny];
            }
        }
    }
    return maxi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n;i++){
        cin >> s;
        for(int j=0; j<s.size();j++){
            board[i][j]=s[j];
        }
    }
    int ans = -1;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(board[i][j]=='L') {
                int tmp = bfs(i,j);
                if(tmp > ans){
                    ans = tmp;
                }
            }
            reset();
        }
    }
    cout << ans;

    return 0;
}