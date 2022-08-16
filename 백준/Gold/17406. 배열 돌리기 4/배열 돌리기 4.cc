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

int n,m,k,mini=987654321;
int arr[51][51],arr2[51][51];
vector<pair<pair<int,int>,int>> v;
int order[6]; //회전연산 순서
bool check[6]; //선택한 회전연산 표시

void copy(){
    for(int i=1; i<=n;i++){
        for(int j=1;j<=m;j++){
            arr2[i][j] = arr[i][j];
        }
    }
}

void rolling(int r, int c, int s){
    while(s>=1) {
        int top = arr2[r - s][c - s];
        //왼쪽변
        for (int i = r - s + 1; i <= r + s; i++) {
            arr2[i - 1][c - s] = arr2[i][c - s];
        }
        //아래쪽변
        for (int i = c - s + 1; i <= c + s; i++) {
            arr2[r + s][i - 1] = arr2[r + s][i];
        }
        //오른쪽변
        for (int i = r + s - 1; i >= r - s; i--) {
            arr2[i + 1][c + s] = arr2[i][c + s];
        }
        //위쪽변
        for (int i = c + s - 1; i > c - s; i--) {
            arr2[r - s][i + 1] = arr2[r - s][i];
        }
        arr2[r - s][c - s + 1] = top;
        s--;
    }
}
void roll(){
    copy();
    for(int i=0; i<k;i++){
        int ord = order[i];
        int R = v[ord].first.first;
        int C = v[ord].first.second;
        int S = v[ord].second;
        rolling(R,C,S);
    }

    for (int i = 1; i <= n; i++) {
        int res=0;
        for (int j = 1; j <= m; j++) {
            res += arr2[i][j];
        }
        mini = min(mini, res);
    }
}

void dfs(int depth){
    if(depth == k){
        roll();
        return;
    }
    for(int i=0; i<k;i++){
        if(check[i]) continue;
        check[i]=true;
        order[depth] = i;
        dfs(depth+1);
        check[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    for(int i=1;i<=n;i++){
        for(int j=1; j<=m;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<k;i++){
        int r,c,s;
        cin >> r >> c >> s;
        v.push_back({{r,c},s});
    }
    dfs(0);
    cout << mini;
}