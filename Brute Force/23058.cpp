#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*#include <iostream>
#include <string>
#include <queue>
#include <set>*/

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y;
};

struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y < b.y;
    }
};
priority_queue <P, vector<P>, compare> pq;

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

void solved() {
    int N; cin >> N;
    int M[8][8] = { 0, };
    int m[8][8] = { 0, };
    rep(i, N) rep(j, N) cin >> M[i][j];

    int ans = 987654321;
    for (int row = 0; row < pow(2, N); row++) {
        rep(i, N) rep(j, N) m[i][j] = M[i][j];

        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (row & (1 << j)) {
                cnt += 1;

                for (int k = 0; k < N; k++) {
                    if (m[j][k] == 1) m[j][k] = 0;
                    else m[j][k] = 1;
                }
            }
        }

        for (int column = 0; column < pow(2, N); column++) {
            int ttmp[8][8] = { 0, };
            rep(i, N) rep(j, N) ttmp[i][j] = m[i][j];

            int cnt2 = 0;
            for (int j = 0; j < N; j++) {
                if (column & (1 << j)) {
                    cnt2 += 1;

                    for (int k = 0; k < N; k++) {
                        if (ttmp[k][j] == 1) ttmp[k][j] = 0;
                        else ttmp[k][j] = 1;
                    }
                }
            }

            int tmp = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (ttmp[i][j] == 1) tmp++;
                }
            }

            cnt2 += min(tmp, N * N - tmp);

            ans = min(ans, cnt + cnt2);
        }
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
