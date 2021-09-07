#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    int N; cin >> N;
    vector <ll> v(N - 1), m(N);

    rep(i, N - 1) cin >> v[i];
    rep(i, N) cin >> m[i];

    ll ans = 0;

    for (int i = 0; i < N - 1; i++) {
        ll tmp = v[i];
        ll ttmp = m[i];
        while (i < N - 2 && ttmp <= m[i + 1]) {
            i++;
            tmp += v[i];
        }

        ans += (tmp * ttmp);
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
