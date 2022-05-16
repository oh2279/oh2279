#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int N, K, L;
int MAP[101][101];

// 오른, 왼, 아래, 위
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<pair<int, char>> V;

int Turn_Direction(int d, char c)
{
    if (c == 'L')//왼쪽으로 회전할 때
    {
        if (d == 0) return 3; // 오른쪽으로 진행하고 있었으면, 위로 이동
        else if (d == 1) return 2; // 왼쪽으로 진행하고 있었으면, 아래로 이동
        else if (d == 2) return 0; // 아래로 진행하고 있었으면, 오른쪽으로 이동
        else if (d == 3) return 1; // 위로 진행하고 있었으면, 왼쪽으로 이동
    }
    else if (c == 'D') // 오른쪽으로 회전할 때
    {
        if (d == 0) return 2; // 진행방향 오른쪽이면, 아래로 이동
        else if (d == 1) return 3; // 진행방향 왼쪽이면, 위로 이동
        else if (d == 2) return 1; // 진행방향 아래쪽이면, 왼쪽으로 이동
        else if (d == 3) return 0; // 진행방향 위쪽이면, 오른쪽으로 이동
    }
}

void Solution()
{
    deque<pair<int, int>> Q;
    int x = 0;
    int y = 0;
    int d = 0;
    int Time = 0;
    int Idx = 0;
    Q.push_back(make_pair(x, y));

    MAP[x][y] = 2;// start

    while (1)
    {
        Time++; // 한번 이동할 때 마다 time ++

        int nx = x + dx[d]; // 오른쪽 왼쪽 아래쪽 위쪽 순서로 이동
        int ny = y + dy[d];

        if ((nx < 0 || ny < 0 || nx >= N || ny >= N) || MAP[nx][ny] == 2) // 벽에 닿았거나 내 몸과 닿으면
        {
            break;
        }
        else if (MAP[nx][ny] == 0) // 사과 없으면
        {
            MAP[nx][ny] = 2; // 머리 전진
            MAP[Q.back().first][Q.back().second] = 0; // 꼬리 전진
            Q.pop_back(); // 꼬리 정보 삭제
            Q.push_front(make_pair(nx, ny)); // 새로운 머리 정보 등록
        }
        else if (MAP[nx][ny] == 1) // 사과 있으면
        {
            MAP[nx][ny] = 2; // 머리 전진
            Q.push_front(make_pair(nx, ny)); // 새로운 머리 정보 등록
        }


        if (Idx < V.size()) // 이동횟수보다 아직 덜 이동했으면
        {
            if (Time == V[Idx].first) // 만약 방향 바꿀 시간이 됐다면
            {
                if (V[Idx].second == 'L') d = Turn_Direction(d, 'L'); // 현재 d와 L을 보내 앞으로 갈 d를 정함
                else if (V[Idx].second == 'D') d = Turn_Direction(d, 'D'); // 마찬가지
                Idx++;
            }
        }
        x = nx;
        y = ny;
    }
    cout << Time << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        x = x - 1;
        y = y - 1;
        MAP[x][y] = 1;    // 사과 = 1로 표시
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        V.push_back(make_pair(a, b));
    }
    Solution();

    return 0;
}