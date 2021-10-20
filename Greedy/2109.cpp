#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <stack>
#include <cmath>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;
const int mod = 1000000007;
const int MAX = 1000005;

struct P {
    ll x; ll y; ll cnt;
};

struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x > b.x;
        return
            a.y > b.y;
    }
};
//priority_queue <P, vector<P>, compare> pq;

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

int gcd(int a, int b) {
    while (b != 0) { int r = a % b; a = b; b = r; }
    return a;
}

void solved() {
    int N; cin >> N;

    if (N == 0) {
        cout << 0;
        return;
    }

    vector<P> v(N);
    rep(i, N) cin >> v[i].y >> v[i].x;

    sort(v.begin(), v.end(), cmp);

    priority_queue <int> pq;
    int tmp = N - 1;

    int ans = 0;

    for (int i = v[N - 1].x; 0 < i; i--) {
        while (0 <= tmp && i <= v[tmp].x) {
            pq.push(v[tmp].y);
            tmp--;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
