#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool flag;
	int n, last = 0;

	cin >> n;
	string ans;
	stack<int> s;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num > last) {
			while (num > last) {
				s.push(++last);
				ans += "+";
			}
			s.pop();
			ans += '-';
		}
		else {
			flag = false;
			if (!s.empty()) {
				if (num == s.top()) {
					flag = true;
				}
				s.pop();
				ans += '-';
			}
			if (!flag) {
				cout << "NO\n";
				return 0;
			}
		}
	}

	for (auto x : ans) {
		cout << x << '\n';
	}

}