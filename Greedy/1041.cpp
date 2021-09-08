#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    ll N; cin >> N;
    vector <ll> v(6);
    rep(i, 6) cin >> v[i];

    if (N == 1) {
        sort(v.begin(), v.end());

        cout << v[0] + v[1] + v[2] + v[3] + v[4];
        return;
    }

    ll a = min(v[2], v[3]) + min(v[0] + v[1], min(v[1] + v[5], min(v[5] + v[4], v[0] + v[4])));
    ll b = min(v[0] + v[1], min(v[0] + v[2], min(v[0] + v[3], min(v[0] + v[4],
        min(v[1] + v[2], min(v[1] + v[3], min(v[1] + v[5],
            min(v[2] + v[4], min (v[2] + v[5], min(v[3] + v[4], min(v[3] + v[5], v[4] + v[5])))))))))));
    ll c = min(v[0], min(v[1], min(v[2], min(v[3], min(v[4], v[5])))));

    ll ans = 4 * a;
    ans += (8 * N - 12) * b;
    ans += (5 * N * N - 16 * N + 12) * c;

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
