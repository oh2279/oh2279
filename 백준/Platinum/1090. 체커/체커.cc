#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
int ans[100];

void check(int x, int y)
{
	int i;
	multiset<int> ms;
	int sum = 0;

	for (i = 0; i < v.size(); i++)
	{
		ms.insert(abs(x - v[i].first) + abs(y - v[i].second));
	}

	sum = 0;
	auto it = ms.begin();
	for (i = 1; i <= n; i++)
	{
		sum += *it;
		it++;

		ans[i] = min(ans[i], sum);
	}
}

int main()
{
	int i, j;
	int a, b;
	vector<int> x, y;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a >> b;

		v.push_back(make_pair(a, b));
		x.push_back(a);
		y.push_back(b);
	}

	for (i = 1; i <= n; i++) ans[i] = 1000000000;

	for (i = 0; i < x.size(); i++)
	{
		for (j = 0; j < y.size(); j++)
		{
			check(x[i], y[j]);
		}
	}

	for (i = 1; i <= n; i++)
	{
		cout << ans[i] << ' ';
	}
}