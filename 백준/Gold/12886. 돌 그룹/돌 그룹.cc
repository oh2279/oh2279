#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <cstring>

using namespace std;

int visited[1001][1001];
int a,b,c,sum;

int bfs(){
    queue <pair<int, int>> q;
    q.push({a,b});
    visited[a][b] = 1;

    while (!q.empty()) {
        int x = q.front().first; // a
        int y = q.front().second; // b
        int z = sum - x - y; // c
        q.pop();

        if (x == y && x == z) // 3개가 같으면
            return 1;

        int nx[3] = {x, x, y };
        int ny[3] = {y, z, z };
        // 두 쌍을 고르기 위한 배열

        for (int i = 0; i < 3; i++) {
            int first = nx[i];
            int second = ny[i];
            if (first < second)
                second -= first, first += first;
            else if (first > second)
                first -= second, second += second;
            else // 두개가 같다면 패쓰
                continue;
            int nc = sum - first - second;

            int ra = min(min(first, second), nc);
            int rb = max(max(first, second), nc);
            // 제일 작은거랑 제일 큰거 골라서 다음번 그룹으로 넣어버림

            if (visited[ra][rb] == 0) {
                visited[ra][rb] = 1;
                q.push(make_pair(ra, rb));
            }

        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c;
    sum = a + b + c;
    if ((a + b + c) % 3 != 0)
        cout << 0 << endl;
    else
        cout << bfs() << endl;

    return 0;
}