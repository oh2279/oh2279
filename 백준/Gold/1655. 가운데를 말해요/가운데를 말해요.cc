#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int N,num;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    priority_queue<int> max_pq; // 작은 수들을 넣는 큐
    priority_queue<int,vector<int>,greater<>>  min_pq; // 큰 수들을 넣는 큐
    // 최소 힙의 값들은 최대 힙의 값들보다 무조건 커야한다! == swap해주자!
    // 그리고 최대 힙의 크기는 최소 힙보다 1보다 크거나 같아야한다. == 최대 힙에 값을 먼저 넣어주자!    
    while (N--) {
        cin >> num;
        if (max_pq.size() == min_pq.size()) { // 사이즈가 같으면
            max_pq.push(num); // 최대 힙에 넣는다 -> why? mid가 2개일 경우 더 작은 수를 출력해야하기 때문
        }
        else {
            min_pq.push(num);
        }
        if (!max_pq.empty()&&!min_pq.empty()&&max_pq.top()>min_pq.top()) {
            // 둘다 비어있지않고, 작은 값들 중 최대 값이 큰 값들 중 최소 값보다 크면
            // 두 힙의 top을 swap 해준다!
            int max_val, min_val;
            max_val = max_pq.top();
            min_val = min_pq.top();
            max_pq.pop();
            min_pq.pop();
            max_pq.push(min_val);
            min_pq.push(max_val);
        }
        cout << max_pq.top() << '\n';
    }
}
