#include<iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
int n,m,x,y,k,order;

int board[21][21];

int bottom = 5;
int dice[6] = {0,};
// 0 = 앞쪽
// 1 = 왼쪽
// 2 = 상단
// 3 = 오른쪽
// 4 = 뒤쪽
// 5 = 바닥
int tmp[6];

void reset(){
    for(int z=0; z<6;z++){
        tmp[z] = dice[z];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n>>m>>x>>y>>k;

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> board[i][j];
        }
    }
    for(int i=0;i<k;i++){
        cin >> order;
        if(order == 1){ // 동
            if(y+1 < m){
                y+=1; // 주사위 오른쪽으로 한칸 이동
                if(board[x][y]==0){
                    board[x][y] = dice[3]; // 오른쪽으로 굴리면 오른쪽면이 바닥이 됨
                }
                else{
                    dice[3] = board[x][y];
                    board[x][y]=0;
                }
                cout << dice[1] << '\n';// 오른쪽으로 굴리면 왼쪽면이 상단이 됨
                reset();
                // 주사위 값 재설정
                // 동쪽으로 굴리면 앞,뒤는 안바뀜
                dice[1] =  tmp[5]; // 원래 바닥이 왼쪽면이 됨
                dice[2] =  tmp[1];// 원래 왼쪽면이 상단이 됨
                dice[3] = tmp[2]; // 원래 상단이 오른쪽면이 됨
                dice[5] = tmp[3]; // 원래 오른쪽면이 바닥이 됨
            }

        }
        else if(order==2){// 서
            if(y-1 >=0){
                y-=1; // 주사위 왼쪽으로 한칸 이동
                if(board[x][y]==0){
                    board[x][y] = dice[1]; // 왼쪽으로 굴리면 왼쪽면이 바닥이 됨
                }
                else{
                    dice[1] = board[x][y];
                    board[x][y]=0;
                }
                cout << dice[3] << '\n';// 왼쪽으로 굴리면 오른쪽면이 상단이 됨
                reset();
                // 주사위 값 재설정
                // 서쪽으로 굴리면 앞,뒤는 안바뀜
                dice[3] =  tmp[5]; // 원래 바닥이 오른쪽면이 됨
                dice[5] =  tmp[1];// 원래 왼쪽면이 바닥이 됨
                dice[1] = tmp[2]; // 원래 상단이 왼쪽면이 됨
                dice[2] = tmp[3]; // 원래 오른쪽면이 상단이 됨
            }

        }
        else if(order==4){//남
            if(x+1 < n){
                x+=1; // 주사위 아래쪽으로 한칸 이동
                if(board[x][y]==0){
                    board[x][y] = dice[4]; // 아래쪽으로 굴리면 뒤쪽면이 바닥이 됨
                }
                else{
                    dice[4] = board[x][y];
                    board[x][y]=0;
                }
                cout << dice[0] << '\n';// 아래쪽으로 굴리면 앞쪽면이 상단이 됨
                reset();
                // 주사위 값 재설정
                // 남쪽으로 굴리면 왼,오는 안바뀜
                dice[0] =  tmp[5]; // 원래 바닥이 앞쪽이 됨
                dice[2] =  tmp[0];// 원래 앞면이 상단이 됨
                dice[4] = tmp[2]; // 원래 상단이 뒤쪽면이 됨
                dice[5] = tmp[4]; // 원래 뒤쪽면이 바닥이 됨
            }

        }
        else{ // order==3 북
            if(x-1 >=0){
                x-=1; // 주사위 위쪽으로 한칸 이동
                if(board[x][y]==0){
                    board[x][y] = dice[0]; // 위쪽으로 굴리면 앞쪽면이 바닥이 됨
                }
                else{
                    dice[0] = board[x][y];
                    board[x][y]=0;
                }
                cout << dice[4] << '\n';// 위쪽으로 굴리면 뒤쪽면이 상단이 됨
                reset();
                // 주사위 값 재설정
                // 북쪽으로 굴리면 좌,우는 안바뀜
                dice[4] =  tmp[5]; // 원래 바닥이 뒤면이 됨
                dice[5] =  tmp[0];// 원래 앞면이 바닥이 됨
                dice[0] = tmp[2]; // 원래 상단이 앞면이 됨
                dice[2] = tmp[4]; // 원래 뒤쪽면이 상단이 됨
            }

        }
    }

    return 0;
}
