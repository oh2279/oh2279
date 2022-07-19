#include<iostream>
#include <vector>
using namespace std;

int n;
vector<int> visited(15);

int ans; 

bool Check(int cnt){
    for (int i = 0; i < cnt; i++){
       // 열이 같거나 또는 행간 거리가 열간 거리와 같다면(=대각선이라면) 탈락
        if (visited[cnt] == visited[i] || cnt - i == abs(visited[cnt] - visited[i]))
            return 0;
    }

    //현재 퀸을 배치할 수 있다면 return 1
    return 1;
}

void dfs(int cnt){
    // 현재 배치한 퀸의 갯수가 입력값(N)과 같다면 탈출
    if (cnt == n){
        ans++;
        return;
    }

    // 0번째 행부터 N 행까지 반복
    for (int j = 0; j < n; j++)
    {
        // [qCnt, j] 에 배치해보고
        visited[cnt] = j;

        // 배치할 수 있다면
        if (Check(cnt))
            // 퀸의 행을 + 1 하고 다음 퀸을 배치해본다.
            dfs(cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dfs(0);
    cout << ans;
}