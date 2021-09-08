#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    ll x; ll y; ll z;
};

bool cmp(const P& a, const P& b) {
    if (a.y < b.y) return true;
    else if (a.y == b.y) {
        if (a.x < b.x) return true;
        else return false;
    }
    return false;
}

void solved() {
    ll N, C, M; cin >> N >> C >> M;

    vector <P> v(M);
    rep(i, M) {
        cin >> v[i].x >> v[i].y >> v[i].z;
    }

    sort(v.begin(), v.end(), cmp);

    ll ans = 0;
    
    vector <int> left(N + 1, C);
    rep(i, M) {
        int m = left[v[i].x];
        for (int j = v[i].x + 1; j < v[i].y; j++) {
            m = min(m, left[j]);
        }

        int cnt = v[i].z;

        if (m < cnt) cnt = m;

        ans += cnt;
        for (int j = v[i].x; j < v[i].y; j++) {
            left[j] -= cnt;
        }
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}

/*
택배를 받는 마을이 작은 순으로 정렬(동일하면 보내는 마을이 작은 순)
정렬된 배열을 돌면서 left로 마을에서 마을까지 보낼 수 있는 양을 체크
*/
