#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> q;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() != 1) {
		q.pop();
		int top = q.front();
		if (q.size() == 1) {
			break;
		}
		q.push(top);
		q.pop();
	}

	cout << q.front();
	return 0;
}