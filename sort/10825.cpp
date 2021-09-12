#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y; int z; string name;
};

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y > b.y) return true;
        else if (a.y == b.y) {
            if (a.z < b.z) return true;
            else if (a.z == b.z) {
                if (a.name > b.name) return true;
            }
        }
    }
    return false;
}

void solved() {
    int N; cin >> N;
    vector <P> v(N);
    rep(i, N) cin >> v[i].name >> v[i].x >> v[i].y >> v[i].z;

    sort(v.begin(), v.end(), cmp);

    for (int i = N - 1; 0 <= i; i--) cout << v[i].name << "\n";
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
