#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*#include <iostream>
#include <string>
#include <queue>
#include <set>*/

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    ll x; ll y;
};

/*struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y < b.y;
    }
};
priority_queue <P, vector<P>, compare> pq;*/

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

void solved() {
    int N; cin >> N;
    vector <P> v(N);
    rep(i, N) cin >> v[i].x >> v[i].y;

    ll ans = _INF;
    for (int i = 1; i < pow(2, N); i++) {
        ll tmpX = 1, tmpY = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                tmpX *= v[j].x;
                tmpY += v[j].y;
            }
        }
        ans = min(ans, abs(tmpX - tmpY));
    }
    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
