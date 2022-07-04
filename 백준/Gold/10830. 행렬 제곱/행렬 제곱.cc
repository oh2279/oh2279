#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long N, B;
long long matrix[5][5];
long long temp[5][5];
long long ans[5][5];

// 행렬 곱셈
void Matrix_multi(long long X[5][5], long long Y[5][5])
{

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            temp[i][j] = 0; // 행렬 초기화
            for (int k = 0; k < N; k++)
                temp[i][j] += (X[i][k] * Y[k][j]); // 행렬곱

            temp[i][j] %= 1000;
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            X[i][j] = temp[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> B;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];
        ans[i][i] = 1; // 정답행렬은 단위행렬로
    }

    while (B > 0)
    {
        if (B % 2 == 1)
        {
            Matrix_multi(ans, matrix); // 단위행렬에 A행렬 곱하기
        }
        Matrix_multi(matrix, matrix);
        B /= 2;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << ans[i][j] << " ";
        cout << '\n';
    }
}
