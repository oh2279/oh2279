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

int n,cnt,house;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int board[25][25];
bool visited[25][25];
vector<int> v;
void dfs(int x, int y){
    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=n || nx<0 || ny>=n || ny<0) continue;

        if(!visited[nx][ny] && board[nx][ny]==1){   //방문 안했고 집이 있으면
            visited[nx][ny] = true;
            house++;
            dfs(nx,ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i=0; i<n;i++){
        string s;
        cin >> s;
        for(int j=0; j<s.size();j++){
            board[i][j] = s[j]-'0';
        }
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(board[i][j]==1 && !visited[i][j]){
                visited[i][j] = true;
                house=1;
                dfs(i,j);
                cnt++;
                v.push_back(house);
            }
        }
    }
    sort(v.begin(),v.end());
    cout << cnt << '\n';
    for(int i=0; i<v.size();i++){
        cout << v[i] << '\n';
    }
}