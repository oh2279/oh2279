#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int n, m,s;
vector<int> v[1001];
bool visited[1001];
queue<int> q;

void dfs(int idx) {
	cout << idx << " ";
	visited[idx] = true;
	for (int i = 0; i< v[idx].size(); i++) {
		int next = v[idx][i];
		if (visited[next] == false) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	
	visited[start] = true;

	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		cout << node << " ";
		for (int i = 0; i<v[node].size(); i++) {
			int next = v[node][i];
			if (visited[next] == false) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a,b;
	cin >> n >> m >> s;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(s);
	cout << "\n";
	memset(visited, false, sizeof(visited));

	bfs(s);
}