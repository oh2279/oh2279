#include <iostream>
#include <stdio.h>
#include <math.h>
#include <bitset>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
#define INF 987654321
using namespace std;
typedef pair<int, int> node;

int n,ans,cnt;
int map[MAX][MAX];
int area[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs_area(int r,int c){
    queue<node> q;
    q.push(node(r,c));
    area[r][c] = cnt;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            
            if(area[nx][ny]==-1 && map[nx][ny]==1){
                q.push(node(nx,ny));
                area[nx][ny] = cnt;
            }
        }
    }
}

bool is_adjacentSea(int x,int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        
        if(map[nx][ny]==0) return true;
    }
    return false;
}

void bfs_dist(int r,int c){
    memset(visited, false, sizeof(visited));
    int a_info = area[r][c];
    
    queue<pair<node,int>> q;
    q.push(make_pair(node(r,c), 0));
    visited[r][c] = true;
    
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        
        if(area[x][y] != a_info && map[x][y] == 1){
            ans = min(ans,d-1);
            return;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            
            if((area[nx][ny]!=a_info || area[nx][ny]==-1) && !visited[nx][ny]){
                q.push(make_pair(node(nx,ny), d+1));
                visited[nx][ny] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    
    memset(area, -1, sizeof(area));
    
    // 영역 번호 구하기
    cnt = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(area[i][j]==-1 && map[i][j]==1){
                bfs_area(i,j);
                cnt++;
            }
        }
    }
    
    // 다리 경로 구하기
    ans = INF;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j]==1 && is_adjacentSea(i,j)){
                bfs_dist(i,j);
            }
        }
    }
    cout << ans << "\n";
}