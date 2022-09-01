#include <bits/stdc++.h>

using namespace std;

int elec[101]; // k
int plug[101]; // n

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k,cnt=0;
    bool flag;
    cin >> n >> k;
    for(int i=1; i<=k;i++){
        cin >> elec[i];
    }
    for(int i=1; i<=k;i++) {
        flag = false;
        for (int j = 1; j <= n; j++) {
            if (elec[i] == plug[j]) { // 만약 같은게 꽂혀있다면
                flag = true;
                break;
            }
        }
        if (flag) continue;
        
        // 빈 구멍에 하나 꽂기
        for(int j=1; j<=n ;j++){
            if(plug[j]==0){ // 꽂혀있지 않다면
                plug[j]=elec[i];
                flag=true;
                break;
            }
        }
        if (flag) continue;
        // 만약 다른게 꽂혀있어서 바꿔야 한다면
        cnt++;
        int device=-1,loc;
        for (int j = 1; j <= n; j++) {
            int idx = 0;
            for (int z = i + 1; z <= k; z++) {
                if (plug[j] == elec[z]) break; // 뒤에 같은게 있다면 break
                idx++;
            }
            if (idx > device) { // 제일 뒤에 다시 나오는 놈을 변경
                // idx를 계속 ++ 하기 때문에 아예 안나오는 놈이 제일 큰 값을 가짐
                device = idx;
                loc = j;
            }
        }
        plug[loc]=elec[i];
    }
    cout << cnt;
    return 0;
}