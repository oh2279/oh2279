#include <iostream>
#include <vector>
#include <algorithm>
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

int n;
int room[51][51];
int dx[] ={1,0,-1,0};
int dy[]={0,1,0,-1};
string s;
queue<pair<int,int>> q;
int visited[51][51];

void bfs(){
    q.push({0,0});
    visited[0][0]=0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <0 || ny <0 || nx >= n || ny >= n) continue;

            if(room[nx][ny]==1){
                if(visited[nx][ny] > visited[x][y]){
                    visited[nx][ny] = visited[x][y];
                    q.push({nx,ny});
                }
            }
            else{
                if(visited[nx][ny] > visited[x][y] + 1){
                    visited[nx][ny] = visited[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<s.size();j++){
            room[i][j] = s[j]-'0';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=987654321;
        }
    }

    bfs();

    cout << visited[n-1][n-1];
    return 0;
}
