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

void solved() {
    int N; cin >> N;
    vector<ll> v(N);
    rep(i, N) cin >> v[i];

    sort(v.begin(), v.end());

    ll tmp = 0;
    rep(i, N - 1) tmp += v[i];

    if (tmp <= v[N - 1]) {
        cout << v[N - 1] - tmp;
        return;
    }
    else {
        int i = 0;
        while (tmp > v[N - 1]) {
            if (v[i] * 2 <= tmp - v[N - 1]) {
                v[i + 1] -= v[i];
                tmp -= v[i] * 2;
                v[i] = 0;
            }
            else {
                ll cnt = (tmp - v[N - 1]) / 2;

                if ((tmp - v[N - 1]) % 2 == 1) cnt++;
                v[i] -= cnt;
                v[i + 1] -= cnt;
                tmp -= cnt * 2;
            }
            i++;
        }
        for (int i = 0; i < N - 1; i++) {
            v[N - 1] -= v[i];
            v[i] = 0;
        }
    }
    cout << abs(v[N - 1]);
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
