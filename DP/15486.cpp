#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>*/

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;
const int mod = 1000000007;
const int MAX = 1000005;

struct P {
    ll x; ll y;
};

struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y < b.y;
    }
};
priority_queue <P, vector<P>, compare> pq;

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

int a[1500005][2] = { 0, };
int dp[1500005] = { 0, };

void solved() {
    int N; cin >> N;
    rep(i, N) cin >> a[i + 1][0] >> a[i + 1][1];

    if (a[N][0] == 1) dp[N] = a[N][1];
    for (int i = N - 1; 0 < i; i--) {
        if (N < a[i][0] + i - 1) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i + 1], dp[i + a[i][0]] + a[i][1]);
        }
    }

    cout << dp[1];
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
