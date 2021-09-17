#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y; int time;
};

struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y > b.y;
    }
};
bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

priority_queue <P, vector<P>, compare> pq;

void solved() {
    ll N, M; cin >> N >> M;
    vector <ll> v(N);
    rep(i, N) cin >> v[i];

    ll ans = 0;
    for (ll iter = 1; iter < pow(2, N); iter++) {
        ll cnt = 0;
        ll total = 1;
        for (ll j = 0; j < N; j++) {
            if (iter & (1 << j)) {
                cnt++;
                total *= v[j];
            }
        }

        if (cnt % 2 == 0) {
            ans -= (M / total);
        }
        else {
            ans += (M / total);
        }
    }
    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
