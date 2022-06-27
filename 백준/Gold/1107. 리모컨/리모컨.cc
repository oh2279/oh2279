#include <iostream>
#include <vector>
using namespace std;

int m,num,n,cnt;
vector<bool> button(10);

int check(int n) {
    // 이동하려고 하는 채널이 0인 경우
    if (n == 0){
        if (button[0]){
            return 0;
        }
        else {
            return 1;
        }
    }
    // 이동 하려고 하는 채널이 0이 아닌 경우
    int len = 0;

    while(n > 0){
        // 버튼이 고장난 경우
        if (button[n % 10]) { // 각 자리 수에 대해서 나머지 연산을 통해 한 자리수 씩 뽑아 내어 고장난 버튼이 있는지 판별
            return 0;
        }
        // 고장난 버튼이 없다면
        n = n / 10;
        len += 1;
    }
    // 리모컨을 누른 횟수 반환
    return len;
}

int main() {
    cin >> n >> m;
    while(m--){
        cin >> num;
        button[num]=true;
    }

    if(n==100) {
        cout << 0;
        return 0;
    }

    cnt = abs(n-100); // + - 만 눌렀을 경우 == 최대 횟수

    for (int i=0; i <= 1000000; i++){ // 0번 채널부터 1000000번 채널까지 모두 검사(브루트 포스)
        int channel = i;

        int push = check(channel);

        if (push > 0) {
            int press = abs(channel - n);
            if (cnt > press + push)
                cnt = press + push;
        }
    }
    cout << cnt;
    return 0;
}
