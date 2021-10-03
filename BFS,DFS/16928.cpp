#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>*/

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;
const int mod = 1000000007;
const int MAX = 1000005;

struct P {
    ll x; ll y;
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

int N, M;
vector <int> v[101];
vector <int> vv[101];
bool check[101] = { false, };

int bfs(int x) {
    queue <P> que;
    que.push({ 1, 0 });
    check[1] = true;

    while (!que.empty()) {
        int x = que.front().x;
        int cnt = que.front().y;

        que.pop();

        if (x == 100) return cnt;

        for (int i = 1; i <= 6; i++) {
            int xx = x + i;
            
            if (100 < xx) continue;

            if (v[xx].size() != 0) {
                for (int j = 0; j < v[xx].size(); j++) {
                    if (!check[v[xx][j]]) {
                        que.push({ v[xx][j], cnt + 1 });
                        check[v[xx][j]] = true;
                    }
                }
            }
            else if (vv[xx].size() != 0) {
                for (int j = 0; j < vv[xx].size(); j++) {
                    if (!check[vv[xx][j]]) {
                        que.push({ vv[xx][j], cnt + 1 });
                        check[vv[xx][j]] = true;
                    }
                }
            }
            else if (!check[xx]) {
                que.push({ xx, cnt + 1 });
            }
            check[xx] = true;
        }
    }
    return -1;
}

void solved() {
    cin >> N >> M;
    rep(i, N) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
    }
    rep(i, M) {
        int a, b; cin >> a >> b;
        vv[a].push_back(b);
    }

    cout << bfs(1);
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
