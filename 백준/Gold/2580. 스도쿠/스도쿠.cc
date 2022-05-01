#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> emptied;
bool ending = false;
int cnt;

bool check(pair<int, int> p)
{
    int square_x = p.first / 3; // 3x3 구역
    int square_y = p.second / 3;
    for (int i = 0; i < 9; i++){ // 겹치는게 있으면 false
        if (board[p.first][i] == board[p.first][p.second] && i != p.second) // 행
            return false; 
        if (board[i][p.second] == board[p.first][p.second] && i != p.first) // 열
            return false; 
    }
    for (int i = 3 * square_x; i < 3 * square_x + 3; i++) {
        for (int j = 3 * square_y; j < 3 * square_y + 3; j++) {
            if (board[i][j] == board[p.first][p.second]) {
                if (i != p.first && j != p.second) {
                    return false;
                }
            }
        }
    }
    return true;
}

void sudoku(int N) {
    if (N == cnt) { // 게임 끝
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << ' ';
            cout << '\n';
        } 
        ending = true; 
        return;
    }
    for (int i = 1; i <= 9; i++){ // 1-9 넣어보기
        board[emptied[N].first][emptied[N].second] = i;
        if (check(emptied[N])) {
            sudoku(N + 1);
        }
        if (ending) {
            return;
        }
    }
    board[emptied[N].first][emptied[N].second] = 0; // 답 못찾으면 일단 0
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pair<int, int> spot;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                cnt++;
                spot.first = i;
                spot.second = j;
                emptied.push_back(spot); // 빈칸의 좌표 저장
            }
        }
    }
    sudoku(0);
    return 0;
}
