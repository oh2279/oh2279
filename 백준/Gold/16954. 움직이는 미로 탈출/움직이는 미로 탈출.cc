#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <cstring>

using namespace std;

int dx[]={-1,-1,-1,0,0,1,1,1,0};
int dy[] = {-1,0,1,-1,1,-1,0,1,0};

char board[8][8];
int visited[8][8];
queue<pair<int,int>> q;

bool outofindex (int a, int b){
    return (a < 0 || a >=8 || b < 0 || b>=8);
}

void resetboard(){
    for(int i=6; i>=0;i--) {
        for (int j = 0; j < 8; j++) {
            board[i+1][j]=board[i][j];
        }
    }
    for(int i=0; i < 8; i++) board[0][i] = '.';
}

int bfs(){
    while(!q.empty()) {
        memset(visited,0, sizeof(visited));
        int size = q.size(); // 시간 단위로 수행
        while(size--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(board[x][y] == '#') continue;

            for(int i=0; i<9; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx==0 && ny == 7) return 1;
                if(outofindex(nx,ny) || board[nx][ny]=='#' || visited[nx][ny]){
                    continue;
                }
                q.push({nx,ny});
                visited[nx][ny]=true;
            }
        }
        resetboard();
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pair<int,int> starting = {7,0};

    for(int i=0; i<8;i++){
        for(int j=0; j<8; j++){
            cin >> board[i][j];
        }
    }
    q.push(starting);
    visited[starting.first][starting.second]=true;
    cout << bfs();

    return 0;
}