#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

int r,c,ans;
bool flag;
char map[10001][501];
vector<pair<int,int>> v;
bool visited[10001][501];

int dx[]={-1,0,1};
int dy[]={1,1,1};

void dfs(int x, int y) {
    visited[x][y] = true;
    if( y == c-1){
        flag=true;
        ans++;

        return;
    }

    for(int i=0; i<3; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && nx < r && ny >=0 && ny < c){
            if(map[nx][ny]!='x' && !visited[nx][ny]){
                dfs(nx,ny);
                if(flag) return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<r; i++){
        flag=false;
        dfs(i,0);
    }
    cout << ans;

    return 0;
}