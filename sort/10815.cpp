#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y;
};

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

void solved() {
    int N; cin >> N;
    vector <int> v(N);
    rep(i, N) cin >> v[i];

    int M; cin >> M;
    vector <int> c(M);
    rep(i, M) cin >> c[i];

    set <int> s;
    for (int i = 0; i < N; i++) {
        s.insert(v[i]);
    }

    rep(i, M) {
        if (s.find(c[i]) != s.end()) cout << 1 << " ";
        else cout << 0 << " ";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
