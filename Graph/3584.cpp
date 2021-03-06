#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

int v[10005] = { 0, };

vector <int> bfs(int t) {
    vector <int> ret;

    ret.push_back(t);

    while (1) {
        if (v[t] == 0)
            break;
        t = v[t];
        ret.push_back(t);
    }

    return ret;
}

void solve(int t) {
    rep(i, 10005) v[i] = 0;

    int N; cin >> N;

    rep(i, N - 1) {
        int x, y; cin >> x >> y;
        v[y] = x;
    }

    int x, y; cin >> x >> y;

    vector <int> retA = bfs(x);
    vector <int> retB = bfs(y);

    rep(i, retA.size()) {
        rep(j, retB.size()) {
            if (retA[i] == retB[j]) {
                cout << retA[i] << "\n";
                return;
            }
        }
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    rep(i, t)
        solve(i);
}
