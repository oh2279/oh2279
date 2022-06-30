#include<iostream>
#include <vector>
#include <queue>

using namespace std;

int A,B,C;
bool visited[201][201][201];
vector<int> v;

void bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, C});

    while (!q.empty()) {
        // a,b,c는 현재 물통에 담겨 있는 물
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();

        if (visited[a][b][c]) continue;
        visited[a][b][c] = true;

        if(a==0) v.push_back(c);

        // A->B
        if (a + b > B) q.push({{a + b - B, B}, c}); // B물통의 용량보다 클 경우, B용량만큼만 부움
        else q.push({{0, a+b}, c}); // a와 b가 B물통보다 작거나 같을 경우 다 부움
        // A->C
        if (a + c > C) q.push({{a + c - C, b}, C}); // C물통의 용량보다 클 경우, C용량만큼만 부움
        else q.push({{0, b}, a+c}); // a와 c가 C물통보다 작거나 같을 경우 다 부움
        // B->A
        if (b + a > A) q.push({{A, b + a - A}, c}); // A물통의 용량보다 클 경우, A용량만큼만 부움
        else q.push({{b+a, 0}, c}); // b와 a가 A물통보다 작거나 같을 경우 다 부움
        // B->C
        if (b + c > C) q.push({{a, b + a - C}, C}); // C물통의 용량보다 클 경우, C용량만큼만 부움
        else q.push({{a, 0}, b+c}); // b와 c가 C물통보다 작거나 같을 경우 다 부움
        // C->A
        if (c + a > A) q.push({{A, b}, c + a - A}); // A물통의 용량보다 클 경우, A용량만큼만 부움
        else q.push({{c+a, b}, 0}); // c와 a가 A물통보다 작거나 같을 경우 다 부움
        // C->B
        if (c + b > B) q.push({{a, B}, c + b - B}); // B물통의 용량보다 클 경우, B용량만큼만 부움
        else q.push({{a, c+b}, 0}); // c와 b가 B물통보다 작거나 같을 경우 다 부움
    }
    sort(v.begin(),v.end());
    for(auto k:v){
        cout << k <<' ';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> A >> B >>C;

    bfs();

    return 0;
}
