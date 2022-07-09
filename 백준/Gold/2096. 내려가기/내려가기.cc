#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,a,b,c,tmp,tmp0,tmp1;
int maxdp[3];
int mindp[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cin >> a >> b>> c;
    maxdp[0]=a; mindp[0]=a;
    maxdp[1]=b; mindp[1]=b;
    maxdp[2]=c; mindp[2]=c;


    for(int i=1; i<n; i++){
        cin >> a>>b>>c;
        tmp0 = maxdp[0]; tmp1 = maxdp[1];
        maxdp[0]=max(maxdp[0],maxdp[1]) + a;
        tmp = max(maxdp[1],maxdp[2]);
        maxdp[1]=max(tmp,tmp0) + b;
        maxdp[2]=max(maxdp[2],tmp1) + c;
        // ----------------------------------------
        tmp0 = mindp[0]; tmp1 = mindp[1];
        mindp[0]=min(mindp[0],mindp[1]) + a;
        mindp[1]=min(min(mindp[1],mindp[2]),tmp0) + b;
        mindp[2]=min(mindp[2],tmp1) + c;
    }


    /*for(int i=1; i<=n;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]) + cost[i][0];
        int tmp = max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=max(tmp,dp[i-1][0]) + cost[i][1];
        dp[i][2]=max(dp[i-1][2],dp[i-1][1]) + cost[i][2];
    }*/
    cout << max(max(maxdp[0],maxdp[1]),maxdp[2]) << ' ' << min(min(mindp[0],mindp[1]),mindp[2]);

    return 0;
}