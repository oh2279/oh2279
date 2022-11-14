#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n,k,ans;
queue<pair<int,int>> q;
bool visited[200001];

void bfs(){
    while (!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (num == k) {
            ans = cnt;
            break;
        }

        if (num-1 >= 0 && num-1 < 100001 && !visited[num-1]){
            visited[num-1] = true;
            q.push({ num - 1, cnt + 1 });
        }
        if (num+1 >= 0 && num+1 < 100001 && !visited[num+1]){
            visited[num+1] = true;
            q.push({ num + 1, cnt + 1 });
        }
        if (num*2 >= 0 && num*2 < 100001 && !visited[num*2]){
            visited[num*2] = true;
            q.push({ num *2, cnt + 1 });
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    q.push({n,0});
    visited[n]= true;
    bfs();

    cout << ans;
    return 0;
}