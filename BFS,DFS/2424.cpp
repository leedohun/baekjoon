#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <stack>
#include <cmath>
#include <cstring>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;
const int mod = 1000000007;
const int MAX = 1000005;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

struct P {
    ll x; ll y; ll cnt;
};

struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x > b.x;
        return
            a.y > b.y;
    }
};
//priority_queue <P, vector<P>, compare> pq;

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

int gcd(int a, int b) {
    while (b != 0) { int r = a % b; a = b; b = r; }
    return a;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int temp = x1 * y2 + x2 * y3 + x3 * y1;
    temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
    if (temp > 0) return 1;
    else if (temp < 0) return -1;
    else return 0;
}

int combination(int n, int r){
    if (n == r || r == 0) return 1;
    else return combination(n - 1, r - 1) + combination(n - 1, r);
}

int GCP(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int LCM(int a, int b) {
    return a * b / GCP(a, b);
}

struct Q {
    int y; int x; int cnt;
};

int N, M;

string s[700];
int pirate[700][700] = { 0, }, ret[700][700];
bool vis[700][700] = { false, };

void pirateDFS(int y, int x) {
    memset(pirate, -1, sizeof(pirate));

    queue <Q> que;
    que.push({ y, x, 0});
    pirate[y][x] = 0;

    while (!que.empty()) {
        int y = que.front().y;
        int x = que.front().x;
        int cnt = que.front().cnt;

        que.pop();

        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if (yy < 0 || N <= yy || xx < 0 || M <= xx) continue;
            if (pirate[yy][xx] == -1 && (s[yy][xx] == '.' || s[yy][xx] == 'T')) {
                pirate[yy][xx] = cnt + 1;
                que.push({ yy, xx, cnt + 1 });
            }
        }
    }
}

void watchPirate() {
    memset(ret, INF, sizeof(ret));
    for (int i = 0; i < N; i++) {
        int tmp = INF;
        for (int j = 0; j < M; j++) {
            tmp = min(tmp, pirate[i][j]);
            if (pirate[i][j] < 0) {
                tmp = INF;
                ret[i][j] = -1;
            }
            else
                ret[i][j] = tmp;
        }
        
        tmp = INF;
        for (int j = M - 1; 0 <= j; j--) {
            tmp = min(tmp, pirate[i][j]);
            if (pirate[i][j] < 0) {
                tmp = INF;
            }
            else ret[i][j] = min(tmp, ret[i][j]);
        }
    }

    for (int j = 0; j < M; j++) {
        int tmp = INF;
        for (int i = 0; i < N; i++) {
            tmp = min(tmp, pirate[i][j]);
            if (pirate[i][j] < 0) tmp = INF;
            else ret[i][j] = min(tmp, ret[i][j]);
        }

        tmp = INF;
        for (int i = N - 1; 0 <= i; i--) {
            tmp = min(tmp, pirate[i][j]);
            if (pirate[i][j] < 0) tmp = INF;
            else ret[i][j] = min(tmp, ret[i][j]);
        }
    }
}

void solved() {
    cin >> N >> M;
    rep(i, N) cin >> s[i];
    
    int x, y;
    int xx, yy;
    for (int i = 0; i < N; i++) { // 해적의 위치 파악
        for (int j = 0; j < M; j++) {
            if (s[i][j] == 'V') {
                y = i, x = j;
            }
            if (s[i][j] == 'Y') {
                yy = i, xx = j;
            }
        }
    }

    pirateDFS(y, x);
    watchPirate();

    queue <Q> que;
    que.push({ yy, xx, 0 });
    vis[yy][xx] = true;

    while (!que.empty()) {
        yy = que.front().y;
        xx = que.front().x;
        int cnt = que.front().cnt;

        que.pop();

        if (s[yy][xx] == 'T') {
            cout << "YES";
            return;
        }

        for (int i = 0; i < 4; i++) {
            y = yy + dy[i];
            x = xx + dx[i];

            if (y < 0 || N <= y || x < 0 || M <= x) continue;

            if (!vis[y][x] && (s[y][x] == '.' || s[y][x] == 'T') && cnt + 1 < ret[y][x]) {
                que.push({ y, x, cnt + 1 });
                vis[y][x] = true;
            }
        }
    }
    
    cout << "NO";
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
