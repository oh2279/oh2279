#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<cstring>
using namespace std;

int N, K;
int visited[100001];
deque<int> dq;

int dijk() {
    dq.push_back(N);
    visited[N] = 1;
    while (!dq.empty()) {
        int nx = dq.front();
        dq.pop_front();

        if (nx == K) return visited[K] - 1;

        if (nx * 2 < 100001 && !visited[nx * 2]) {
            dq.push_front(nx * 2);
            visited[nx * 2] = visited[nx];
        }

        // 하나 증가
        if (nx + 1 < 100001 && !visited[nx + 1]) {
            dq.push_back(nx + 1);
            visited[nx + 1] = visited[nx] + 1;
        }

        // 하나 감소
        if (nx - 1 >= 0 && !visited[nx - 1]) {
            dq.push_back(nx - 1);
            visited[nx - 1] = visited[nx] + 1;
        }
    }
    return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> N >> K;
	
    int ans = dijk();
    if (ans != -1) {
        cout << ans;
    }
    return 0;
}