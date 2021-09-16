#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y;
};

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

int N;
int M[18][18] = { 0, };
int tmp[18][18] = { 0, };

int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,-1,1,0,0 };

int ans = 987654321;

void check(int x, int y) {
    for (int i = 0; i < 5; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx < 0 || yy < 0 || N <= xx || N <= yy) continue;

        if (tmp[xx][yy] == 0)
            tmp[xx][yy] = 1;
        else
            tmp[xx][yy] = 0;
    }
}

void solved() {
    cin >> N;
    rep(i, N) rep(j, N) cin >> M[i][j];

    for (int init = 0; init < pow(2, N); init++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tmp[i][j] = M[i][j];
            }
        }

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (init & (1 << i)) {
                cnt++;
                check(0, i);
            }
        }

        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N; j++) {
                if (tmp[i][j]) {
                    check(i + 1, j);
                    cnt++;
                }
            }
        }

        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (tmp[N - 1][i] == 1) {
                flag = false;
                break;
            }
        }

        if (flag)
            ans = min(ans, cnt);
    }

    if (ans == 987654321)
        cout << -1;
    else
        cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
