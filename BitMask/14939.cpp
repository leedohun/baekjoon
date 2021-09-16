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

string m[10];
bool tmp[10][10] = { false, };

int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,-1,1,0,0 };

int ans = 987654321;

void check(int x, int y) {
    for (int i = 0; i < 5; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx < 0 || yy < 0 || 10 <= xx || 10 <= yy) continue;

        tmp[xx][yy] = !tmp[xx][yy];
    }
}

void solved() {
    rep(i, 10) cin >> m[i];

    for (int fir = 0; fir < 1024; fir++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (m[i][j] == 'O')
                    tmp[i][j] = true;
                else
                    tmp[i][j] = false;
            }
        }

        int cnt = 0;
        for (int j = 0; j < 10; j++) {
            if (fir & (1 << j)) {
                cnt++;
                check(0, j);
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                if (tmp[i][j]) {
                    check(i + 1, j);
                    cnt++;
                }
            }
        }

        bool flag = true;
        for (int i = 0; i < 10; i++) {
            if (tmp[9][i]) {
                flag = false;
                break;
            }
        }
        if (flag) ans = min(ans, cnt);
    }

    if (ans != 987654321) cout << ans;
    else cout << -1;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
