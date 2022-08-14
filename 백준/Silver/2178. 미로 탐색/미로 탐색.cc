#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <string>
#include <queue>
#include <functional>
#include <complex>
#include <cmath>
#include <unordered_map>
#include <map>
typedef long long ll;
using namespace std;

int n,m;
int maze[101][101];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
bool visited[101][101];
int dist[101][101];

void bfs(){
    queue<pair<int,int>> q;

    q.push({0,0});
    dist[0][0]=1;
    visited[0][0]=true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x==n-1 && y == m-1) break;

        for(int i=0; i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >=n || ny >=m || maze[nx][ny]==0 || visited[nx][ny]) continue;

            q.push({nx,ny});
            dist[nx][ny]=dist[x][y]+1;
            visited[nx][ny]= true;
        }
    }
   cout << dist[n-1][m-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    string s;
    for(int i=0; i<n;i++){
        cin >> s;
        for(int j=0; j<s.size();j++){
            maze[i][j] = s[j]-'0';
        }
    }
    bfs();
    return 0;
}