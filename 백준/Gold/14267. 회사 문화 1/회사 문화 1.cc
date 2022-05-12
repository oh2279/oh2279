#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[100001];
int good[100001] = { 0, };
int n, m, i, w;

void dfs(int num) {
	for (int i = 0; i < v[num].size(); i++) {
		good[v[num][i]] += good[num];
		dfs(v[num][i]);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		if (i == 1)continue;
		v[tmp].push_back(i);
	}
	for (int j =0; j < m; j++) {
		cin >> i >> w;
		good[i] += w;
	}
	dfs(1);

	for (int i = 1; i <= n; i++) {
		cout << good[i] << ' ';
	}
	return 0;
}