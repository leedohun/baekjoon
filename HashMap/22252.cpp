#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

map <string, int> m;
priority_queue <int> pq[100005];

int cnt = 0;

void solve(int t) {
    int Q; cin >> Q;

    ll ret = 0;
    rep(i, Q) {
        int dir; cin >> dir;

        if (dir == 1) {
            string a; int k;
            cin >> a >> k;

            if (m.find(a) == m.end())
                m[a] = cnt++;

            rep(i, k) {
                int tmp; cin >> tmp;
                pq[m[a]].push(tmp);
            }
        }
        else {
            string a; int k;
            cin >> a >> k;

            if (m.find(a) != m.end()) {
                while (!pq[m[a]].empty() && k--) {
                    ret += pq[m[a]].top();
                    pq[m[a]].pop();
                }
            }
        }
    }

    cout << ret;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    //int t; cin >> t;
    //rep(i, t)
        solve(1);

        return 0;
}
