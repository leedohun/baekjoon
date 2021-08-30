#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    int N; cin >> N;
    vector <pair<int, int>> v(N);

    rep(i, N) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    ll ans = 0;

    int fir = v[0].first;
    int sec = v[0].second;

    for (int i = 1; i < N; i++) {
        if (v[i].first <= sec) {
            sec = max(sec, v[i].second);
        }
        else {
            ans += abs(sec - fir);

            fir = v[i].first;
            sec = v[i].second;
        }
    }
    ans += abs(sec - fir);

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
