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

int v[100005] = { 0, };
int dp[100005] = { 0, };

void solved() {
    int N; cin >> N;
    rep(i, N) cin >> v[i + 1];
    
    dp[0] = 0; dp[1] = v[1];
    dp[2] = max(v[2], (v[2] / 2) + v[1]);
    dp[3] = max(v[1] + v[2] / 2, max(v[1] + v[3], v[2] + v[3] / 2));

    for (int i = 4; i <= N; i++) {
        dp[i] = max(dp[i - 4] + v[i - 2] + v[i - 1] / 2, max(dp[i - 4] + v[i - 2] + v[i],
                max(dp[i - 4] + v[i - 1] + v[i] / 2, max(dp[i - 3] + v[i - 1] + v[i] / 2, dp[i - 2] + v[i]))));
    }

    cout << dp[N];
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
