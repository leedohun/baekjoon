#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

int N;

int s[10005][6] = { 0, };
map <int, int> m;

int ret = 0;

void dfs(int f, int down, int up, int cnt) {
    int tmp = 0;
    rep(i, 6) {
        if (i != down && i != up)
            tmp = max(tmp, s[f][i]);
    }
    
    if (f == N - 1) {
       ret = max(ret, (cnt + tmp));
       return;
    }

    rep(i, 6) {
        if (s[f + 1][i] == s[f][up]) {
            dfs(f + 1, i, m[i], cnt + tmp);
        }
    }
}

void solve(int t) {
    cin >> N;

    rep(i, N) rep(j, 6) cin >> s[i][j];

    rep(i, 6) {
        int j = m[i];
        
        dfs(0, i, j, 0);
    }

    cout << ret;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    m[0] = 5; m[5] = 0; m[1] = 3; m[3] = 1; m[2] = 4; m[4] = 2;

    //int t; cin >> t;
    //rep(i, t)
        solve(1);

        return 0;
}
