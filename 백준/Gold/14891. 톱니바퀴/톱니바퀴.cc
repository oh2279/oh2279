#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <string>
#include <queue>
#include <functional>
#include <complex>
#include <cmath>
#include <unordered_map>
#include <map>
typedef long long ll;
using namespace std;

int right_idx=2, left_idx=6;
int k,number,d;
string s;
deque<int> dq[5];
bool check[5];
int dir[5];

void change(deque<int> &deq, int dir, bool visit, int cnt) {
    if(visit) {
        if (cnt % 2 != 0) { // 반대로 회전
            if (dir == 1) dir = -1; // 1->-1
            else dir = 1; // -1 -> 1
        }
        if (dir == 1) { // 시계
            int back = deq.back();
            deq.pop_back();
            deq.push_front(back);
        } else {
            int front = deq.front();
            deq.pop_front();
            deq.push_back(front);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i=1; i<=4;i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            dq[i].push_back(s[j] - '0');
        }
    }

    cin >> k;
    for(int i=0 ;i<k;i++){
        cin >> number >> d;
        int cnt=0;
        memset(check,false,sizeof(check));
        memset(dir,0,sizeof(dir));

        check[number]=true;
        dir[number]=cnt;
        if(number==1) { // 오른쪽만 체크
            while (number <= 3 && ( dq[number][right_idx] != dq[number + 1][left_idx])) {
                //오른쪽 톱니와 맞물린 곳이 다른 극이라면
                // dq[++number]회전 ++
                number++;
                cnt++;
                check[number]=true;
                dir[number]=cnt;
            }
        }
        else if(number == 4){ // 왼쪽만 체크
            while (number >= 2 && (dq[number][left_idx] != dq[number-1][right_idx])) {
                // 왼쪽 톱니와 맞물린 곳이 다른 극이라면
                // dq[--number]회전
                number--;
                cnt++;
                check[number]=true;
                dir[number]=cnt;
            }
        }
        else{
            int tmp = number;
            // 일단 오른쪽 쭉 검사
            while (number <= 3 && ( dq[number][right_idx] != dq[number + 1][left_idx])) {
                //오른쪽 톱니와 맞물린 곳이 다른 극이라면
                // dq[++number]회전
                number++;
                cnt++;
                check[number]=true;
                dir[number]=cnt;
            }
            number = tmp;
            cnt=0;
            while (number >= 2 && (dq[number][left_idx] != dq[number-1][right_idx])) {
                //오른쪽 톱니와 맞물린 곳이 다른 극이라면
                // dq[--number]회전
                number--;
                cnt++;
                check[number]=true;
                dir[number]=cnt;
            }
        }
        for(int z=1;z<=4;z++){
            change(dq[z],d,check[z],dir[z]);
        }
    }
    int ans=0;
    for(int i=1; i<=4;i++){
        if(dq[i][0]==0) ans+=0;
        else{
            ans = ans + int(pow(2,(i-1)));
        }
    }
    cout << ans;
}