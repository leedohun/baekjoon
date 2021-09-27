#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*#include <iostream>
#include <string>
#include <queue>
#include <set>*/

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;
const int mod = 1000000007;
const int MOD = 998244353;
const int MAX = 1000005;

struct P {
    ll x; ll y;
};

/*struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x > b.x;
        return
            a.y > b.y;
    }
};
priority_queue <P, vector<P>, compare> pq;*/

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

int dp[105][1030] = { 0, };

void solved() {
    int n, t, p; cin >> n >> t >> p;

    vector<P> v(t);
    rep(i, t) {
        cin >> v[i].x >> v[i].y;
        v[i].x = v[i].x / 100 * 60 + v[i].x % 100 - 540;
        v[i].y = v[i].y / 100 * 60 + v[i].y % 100 - 540;
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < t; i++) {
        vector <int> tmp;
        for (int j = 1; j <= n; j++) {
            if (dp[j][v[i].x] == 0) {
                tmp.push_back(j);
            }
        }
        int local = 0, tt = 0;
        if (tmp.size() == n) local = 1;
        else {
            for (int j = 0; j < tmp.size(); j++) {
                int cnt = 0, a = tmp[j], b = tmp[j];
                while (dp[a][v[i].x] == 0 && dp[b][v[i].x] == 0) {
                    if (1 < a) a--;
                    if (b < n) b++;
                    cnt++;
                }

                if (tt < cnt) {
                    local = tmp[j]; tt = cnt;
                }
            }
        }

        for (int j = v[i].x; j < v[i].y; j++) {
            dp[local][j] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < 720; i++) {
        if (dp[p][i] == 0) ans++;
    }
    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
