#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

int N, M;

int v[1005][1005] = { 0, };

int dx[4] = { 0,0,-1,1 }; int dy[4] = { 1,-1,0,0 };

map <int, int> m;

void bfs(int a, int b, int cnt) {
    int ret = 1;

    queue<pair<int, int>> q;
    q.push({ a, b });
    v[a][b] = cnt;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        rep(i, 4) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || yy < 0 || N <= x || M <= y) continue;
            if (v[xx][yy] == 1) {
                v[xx][yy] = cnt;
                ret++;
                q.push({ xx, yy });
            }
        }
    }

    m[cnt] = ret;
}

void solve(int t) {
    cin >> N >> M;
    
    rep(i, N) {
        rep(j, M) {
            cin >> v[i][j];
        }
    }

    int cnt = 2;
    rep(i, N) {
        rep(j, M) {
            if (v[i][j] == 1) {
                bfs(i, j, cnt++);
            }
        }
    }

    int ret = 0;
    rep(i, N) {
        rep(j, M) {
            if (v[i][j] == 0) {
                int tmp = 0;

                set <int> s;

                rep(k, 4) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x < 0 || y < 0 || N <= x || M <= y) continue;

                    if (v[x][y] != 0 && s.find(v[x][y]) == s.end()) {
                        tmp += m[v[x][y]];
                        s.insert(v[x][y]);
                    }
                }

                ret = max(ret, tmp);
            }
        }
    }

    cout << ret + 1;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    //int t; cin >> t;
    //rep(i, t)
        solve(1);

        return 0;
}

/*
첫음 input으로 받은 1들을 같은 집합으로 counting을 매겨준다.

0 0 1
0 1 0
1 0 1
1 1 1
-->
0 0 2
0 3 0
4 0 4
4 4 4 이렇게 count 매겨 준 뒤 브루트 포스 알고리즘을 통해서 최대 값을 찾아준다.
*/
