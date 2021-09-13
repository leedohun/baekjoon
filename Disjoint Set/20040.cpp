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

int parent[500005] = { 0, };

void init(int N)
{
    for (int i = 0; i < N; i++)
        parent[i] = i;
}

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        if (x < y)
            parent[y] = x;
        else
            parent[x] = y;

        return false;
    }

    if (x == y) return true;
}

void solved() {
    int N, M; cin >> N >> M;
    vector <P> v(M);
    rep(i, M) cin >> v[i].x >> v[i].y;

    init(N);

    vector <P> tmp;
    rep(i, M) {
        int x = min(v[i].x, v[i].y);
        int y = max(v[i].x, v[i].y);

        if (Union(x, y)) {
            cout << i + 1;
            return;
        }
    }
    cout << 0;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
