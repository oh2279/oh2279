#include <iostream>
#include <stack>
#include<string>
using namespace std;


int main() {
	int cnt = 0;
	int flag = 0;
	string str;

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		stack<char> s;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				s.push(str[j]);
			}
			else if (str[j] == ')') {
				if (s.empty()) {
					flag = 1;
					break;
				}
				else {
					s.pop();
				}
			}
		}
		if (!s.empty() || flag == 1) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
		flag = 0;
	}
	return 0;
}