#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    int N; cin >> N;
    vector <int> v(N);
    rep(i, N) cin >> v[i];

    int ans = 0;
    for (int i = N - 2; 0 <= i; i--) {
        if (v[i + 1] <= v[i]) {
            ans += v[i] - (v[i + 1] - 1);
            v[i] = v[i + 1] - 1;
        }
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
