#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		priority_queue<int, vector<int> >max_pq; // 최대 힙
		priority_queue<int, vector<int>, greater<int> >min_pq; // 최소 힙
		map<int, int>mp;
		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			char cmd; cin >> cmd;
			if (cmd == 'I') {
				int n; cin >> n;
				max_pq.push(n);
				min_pq.push(n);
				mp[n]++;
			}
			else {
				int n; cin >> n;
				if (n == 1) {
					while (!max_pq.empty() && mp[max_pq.top()] == 0) max_pq.pop();
					if (max_pq.empty()) continue;
					else {
						int x = max_pq.top();
						max_pq.pop();
						mp[x]--;
					}
				}
				else {
					while (!min_pq.empty() && mp[min_pq.top()] == 0) min_pq.pop();
					if (min_pq.empty()) continue;
					else {
						int x = min_pq.top();
						min_pq.pop();
						mp[x]--;
					}
				}
			}
			while (!max_pq.empty() && mp[max_pq.top()] == 0) max_pq.pop();
			while (!min_pq.empty() && mp[min_pq.top()] == 0) min_pq.pop();
			
		}
		if (max_pq.empty()) cout << "EMPTY\n";
		else {
			cout << max_pq.top() << " " << min_pq.top() << "\n";
		}
	}
	return 0;
}