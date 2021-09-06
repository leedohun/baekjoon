#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    int N; cin >> N;

    vector <int> v(N);
    rep(i, N) cin >> v[i];

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = v.size() - 1; 0 <= i; i--) {
        ans = max(ans, v[i] * int(v.size() - i));
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
