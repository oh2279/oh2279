#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, num,cnt;
int arr[41][41];
vector<int> ans;

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> num;

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            vector<int> v;
            for (int ii = 0; ii <= 2; ii++) {
                for (int jj = 0; jj <= 2; jj++) {
                    v.push_back(arr[i + ii][j + jj]);
                }
            }
            sort(v.begin(), v.end());
            ans.push_back(v[4]);
        }
    }
    for(int i=0; i<ans.size();i++){
        if(ans[i]>=num){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}