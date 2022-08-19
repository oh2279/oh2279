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

int k,w,h;
int board[210][210];
bool visited[210][210][31];

int dx[]={0,1,0,-1};
int dy[] = {1,0,-1,0};

int hx[] = {-2,-2,-1,1,2,2,1,-1};
int hy[] = {-1,1,2,2,1,-1,-2,-2};

void bfs(){
    // {x,y 좌표쌍} , {이동횟수 , 말처럼 이동한 횟수 쌍}
    queue<pair<pair<int,int>,pair<int,int>>>q;
    q.push({{0,0},{0,0}}); // start
    visited[0][0][0]=true;

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int able = q.front().second.second;
        q.pop();

        if (x == h - 1 && y == w - 1) {
            cout << cnt;
            return;
        }
        if (able < k) { // 말처럼 이동 가능하면
            for (int i = 0; i < 8; i++) {
                int nx = x + hx[i];
                int ny = y + hy[i];
                if (nx >= 0 & nx < h && ny >= 0 && ny < w && !visited[nx][ny][able + 1] && board[nx][ny] == 0) {
                    q.push({{nx, ny}, {cnt+1,able+1}});
                    visited[nx][ny][able+1] = true;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 & nx < h && ny >= 0 && ny < w && !visited[nx][ny][able] && board[nx][ny] == 0) {
                q.push({{nx, ny}, {cnt+1,able}});
                visited[nx][ny][able] = true;
            }
        }
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k >> w >> h;

    for(int i=0; i<h;i++){
        for(int j=0; j<w;j++){
            cin >> board[i][j];
        }
    }
    bfs();
}