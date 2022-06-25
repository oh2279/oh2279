#include<iostream>
#include<algorithm>
#include<list>
#include<string>

using namespace std;

list<char> li;
list<char>::iterator iter ; //반복자 선언

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	char instruction, ch;
	int n;

	cin >> s >> n;

	for (int i = 0; i < s.length(); i++) {
		li.push_back(s[i]);
	}
	iter = li.end();

	while (n--) {
		cin >> instruction;
		if (instruction == 'P') {
			cin >> ch;
			if (iter == li.end()) { // 맨 뒤면 맨 뒤에 삽입
				li.push_back(ch);
				iter = li.end();
			}
			else { // 아니면 중간에 삽입
				li.insert(iter, ch);
				//iter++;
			}
			
		}
		else if (instruction == 'L') { // 맨 앞 아니면 커서 왼쪽으로 이동시킴
			if (iter != li.begin()) {
				iter--;
			}
		}
		else if (instruction == 'D') { // 맨 뒤 아니면 커서 오른쪽으로 이동시킴
			if (iter != li.end()) {
				iter++;
			}
		}
		else if (instruction == 'B') {
			if (iter == li.end()) { // 커서가 맨 오른쪽이면 맨 뒤 삭제
				li.pop_back();
				// iter = li.end();
			}
			else if (iter == li.begin()) { // 커서가 맨 앞이면 무시
				continue;
			}
			else { // 맨 앞, 맨 뒤 모두 아니면 커서 왼쪽의 문자 삭제
				iter--;
				iter = li.erase(iter);
			}
		}
	}
	for (iter = li.begin(); iter != li.end(); iter++) {
		cout << *iter;
	}
}