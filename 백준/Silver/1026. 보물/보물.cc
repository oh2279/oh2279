#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

int n,s;
int A[51];
int B[51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    for(int i=0; i<n; i++){
        cin >> B[i];
    }
    sort(A,A+n,greater<>());
    sort(B,B+n,less<>());
    for(int i=0; i<n; i++){
        s += A[i] * B[i];
    }
    cout << s;
}