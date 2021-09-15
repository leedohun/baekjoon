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

int parent[1000005] = { 0, };

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

void init(int N) {
    rep(i, N + 1) parent[i] = i;
}

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int c, int x, int y) {
    x = Find(x);
    y = Find(y);

    if (c == 1) {
        if (x == y)
            return true;
        else
            return false;
    }

    if (x < y) {
        parent[y] = x;
    }
    else {
        parent[x] = y;
    }
    return true;
}

void solved() {
    int N, M; cin >> N >> M;

    init(N);

    rep(i, M) {
        int c, a, b; cin >> c >> a >> b;

        if (c == 0) {
            Union(0, a, b);
        }
        else {
            if (Union(1, a, b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
