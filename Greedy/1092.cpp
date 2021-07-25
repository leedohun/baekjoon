#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

int ret = 0;

void solve(int t) {
    int N, K; cin >> N;
    vector <int> v(N);
    vector <bool> check(N);
    rep(i, N) cin >> v[i];

    cin >> K;
    vector <int> m(K);
    vector <bool> che(K, false);
    rep(i, K) cin >> m[i];

    sort(v.begin(), v.end());
    sort(m.begin(), m.end());

    if (v[v.size() - 1] < m[m.size() - 1]) {
        cout << -1;
        return;
    }

    int cnt = 0;

    while (cnt != K) {
        rep(i, N) {
            if (check[i])
                continue;
            for (int j = m.size() - 1; 0 <= j; j--) {
                if (!che[j] && m[j] <= v[i]) {
                    che[j] = true;
                    cnt++;
                    break;
                }

                if (j == 0) {
                    check[i] = true;
                }
            }
        }
        ret++;
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
