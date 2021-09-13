#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y; int dir;
};

int dx[8] = { 0,1,0,-1,1,1,-1,-1 };
int dy[8] = { 1,0,-1,0,1,-1,1,-1 }; //하, 우, 상, 좌, 대각선
string M[50];

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

void solved() {
    int N; cin >> N;
    string A; cin >> A;
    rep(i, N) cin >> M[i];

    vector <P> v;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (M[i][j] == 'Z') {
                v.push_back({ j, i, 0 });
                M[i][j] = 'O';
            }
        }
    }

    int x = 0, y = 0, dir = 100;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 'F') {
            if (!(x + dx[(dir % 4)] < 0 || y + dy[(dir % 4)] < 0
                || N <= x + dx[(dir % 4)] || N <= y + dy[(dir % 4)])) {
                x += dx[dir % 4];
                y += dy[dir % 4];
            }
        }
        else if (A[i] == 'L') {
            dir += 1;
        }
        else if (A[i] == 'R') {
            dir -= 1;
        }

        if (M[y][x] == 'S') {
            for (int j = 0; j < 8; j++) {
                int xx = x + dx[j];
                int yy = y + dy[j];

                if (xx < 0 || yy < 0 || N <= xx || N <= yy) continue;
                if(M[yy][xx] == 'O') M[yy][xx] = 'Q';
            }
        }

        for (int j = 0; j < v.size(); j++) {
            if (M[y][x] == 'O' && x == v[j].x && y == v[j].y) {
                cout << "Aaaaaah!";
                return;
            }

            if (v[j].dir == 2 && v[j].y == 0) {
                v[j].dir = 0;
            }
            else if (v[j].dir == 0 && v[j].y == N - 1) {
                v[j].dir = 2;
            }
            else {
                v[j].y += dy[v[j].dir];
            }

            if (M[y][x] == 'O' && x == v[j].x && y == v[j].y) {
                cout << "Aaaaaah!";
                return;
            }
        }
    }

    cout << "Phew...";
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
