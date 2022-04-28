#include<iostream>
#include<stack>
#include<string>
using namespace std;

int n=0,flag=0;
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		flag = 0;
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
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
		
	}
	return 0;
}