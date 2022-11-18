#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n,k,ans2;
int ans = 987654321;
queue<pair<int,int>> q;
bool visited[200001];

void bfs(){
    while (!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();

        visited[num]= true;

        if(ans < cnt) break;

        if (num == k) {
            ans = cnt;
            ans2++;
            continue;
        }

        if (num-1 >= 0 && num-1 < 100001 && !visited[num-1]){
            q.push({ num - 1, cnt + 1 });
        }
        if (num+1 >= 0 && num+1 < 100001 && !visited[num+1]){
            q.push({ num + 1, cnt + 1 });
        }
        if (num*2 >= 0 && num*2 < 100001 && !visited[num*2]){
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
    bfs();

    cout << ans << '\n' << ans2;
    return 0;
}