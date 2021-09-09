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
    int N; cin >> N;
    vector <int> v(N);
    rep(i, N) cin >> v[i];

    sort(v.begin(), v.end());
    
    int M = 0;
    int j = 2;
    for (int i = N - 1; 0 <= i; i--) {
        M = max(M, v[i] + j);
        j++;
    }

    cout << M;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
