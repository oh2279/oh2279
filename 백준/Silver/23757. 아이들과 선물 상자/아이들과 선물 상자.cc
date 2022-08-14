#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		pq.push(c);
	}

	bool flag = true;
	for (int i = 0; i < m; i++)
	{
		int w;
		cin >> w;

		if (pq.top() >= w)
		{
			pq.push(pq.top() - w);
			pq.pop();
		}
		else
			flag = false;
	}

	cout << (flag ? 1 : 0);
	return 0;
}