#include<iostream>
#include<queue>
using namespace std;

int n, k,idx=0;
queue<int> q;
int arr[5001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			int front = q.front();
			q.pop();
			q.push(front);
		}
		arr[idx++] = q.front();
		q.pop();
	}
	cout << "<";
	for (int i = 0; i < idx-1; i++) {
		cout << arr[i] << ", ";
	}
	cout << arr[idx-1] << ">";
}