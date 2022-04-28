#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,top;
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	int ans, cnt = 0;
	cin >> ans;
	if (n != 1) {
		for (int i = 0; i < n - 1; i++) {
			int num;
			cin >> num;
			pq.push(num);
		}
		while (pq.top() >= ans) {
			ans++;
			cnt++;
			top = pq.top();
			pq.pop();
			top--;
			pq.push(top);
		}
	}
	cout << cnt;
	return 0;
}