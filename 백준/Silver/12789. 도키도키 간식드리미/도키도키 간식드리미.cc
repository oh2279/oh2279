#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<stack>
#include<queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;
	stack<int> s;
	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}
	int order = 1;

	while (!q.empty()) {
		int cur = q.front();

		if (cur == order)
		{
			q.pop();
			order++;
		}
		else
		{
			if (!s.empty() && order == s.top())
			{
				s.pop();
				order++;
			}
			else
			{
				s.push(cur);
				q.pop();
			}
		}
    }
	while (!s.empty())
	{
		if (order != s.top())
		{
			break;
		}
		else
		{
			s.pop();
			order++;
		}
	}

	cout << ((s.empty()) ? "Nice" : "Sad") << "\n";
	return 0;
}
