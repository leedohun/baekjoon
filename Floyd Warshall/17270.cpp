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

int v[105][105] = { 0, };
void solved() {
    rep(i, 105) rep(j, 105)
        if (i != j) v[i][j] = INF;

    int V, M; cin >> V >> M;
    rep(i, M) {
        int a, b, c; cin >> a >> b >> c;
        v[a][b] = min(v[a][b], c);
        v[b][a] = v[a][b];
    }

    int J, S; cin >> J >> S;
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (v[i][k] + v[k][j] < v[i][j])
                    v[i][j] = v[i][k] + v[k][j];
            }
        }
    }

    int ans = -1, total = INF, dist = INF;
    if (v[J][S] == INF) {
        cout << -1;
        return;
    }

    for (int i = 1; i <= V; i++) {
        if (i == S || i == J) continue;
        if (v[i][S] == INF || v[i][J] == INF) continue;
        total = min(total, v[i][S] + v[i][J]);
    }

    for (int i = 1; i <= V; i++) {
        if (i == S || i == J) continue;
        if (v[i][S] == INF || v[i][J] == INF) continue;
        if (total != v[i][S] + v[i][J]) continue;
        if (v[i][J] > v[i][S]) continue;

        if (dist > v[i][J]) {
            ans = i;
            dist = v[i][J];
        }
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
