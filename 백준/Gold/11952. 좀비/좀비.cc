#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100005
#define LL long long
#define INF 2e9

using namespace std;
int N, M, K, S;
LL P, Q;
bool Zombie[MAX];
bool visited[MAX];
LL Cost[MAX];
LL DP[MAX];
vector<int> Vec[MAX];

void init() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
		DP[i] = LLONG_MAX;
	}
}

void BFS(int X) {
	init();
	queue<pair<int, LL> > Que;
	visited[X] = true;
	Cost[X] = 0;
	Que.push(make_pair(X, 0));

	while (!Que.empty()) {
		int CurX = Que.front().first;
		LL CurS = Que.front().second;
		Que.pop();

		for (int i = 0; i < Vec[CurX].size(); i++) {
			int nextX = Vec[CurX][i];
			if (!visited[nextX] && (CurS + 1 <= S) && (!Zombie[nextX])) {
				visited[nextX] = true;
				Cost[nextX] = Q;
				Que.push(make_pair(nextX, CurS + 1));
			}
		}
	};
}

void Dijkstra() {
	priority_queue<pair<LL, int> > PQ;
	DP[1] = 0;
	PQ.push(make_pair(0, 1));

	while (!PQ.empty()) {
		LL CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < Vec[CurX].size(); i++) {
			int nextX = Vec[CurX][i];
			if (Zombie[nextX]) {
				continue;
			}
			LL nextCost = CurCost + Cost[nextX];
			if (nextCost < DP[nextX]) {
				DP[nextX] = nextCost;
				PQ.push(make_pair(-nextCost, nextX));
			}
		}
	};
}

int main() {
	FIRST
	cin >> N >> M >> K >> S;
	cin >> P >> Q;
	for (int i = 1; i <= N; i++) {
		Cost[i] = P;
	}
	for (int i = 0; i < K; i++) {
		int X;
		cin >> X;
		Zombie[X] = true;
	}
	for (int i = 0; i < M; i++) {
		int X, Y;
		cin >> X >> Y;
		Vec[X].push_back(Y);
		Vec[Y].push_back(X);
	}
	for (int i = 1; i <= N; i++) {
		if (Zombie[i]) {
			BFS(i);
		}
	}
	Dijkstra();
	cout << DP[N] - Cost[N] << "\n";

	return 0;
}