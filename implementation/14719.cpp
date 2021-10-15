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
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solved() {
    int H, W; cin >> H >> W;
    vector <int> v(W);
    rep(i, W) cin >> v[i];

    ll ans = 0;
    for (int i = 1; i < W - 1; i++) {
        int left = v[i], right = v[i];

        for (int j = i - 1; 0 <= j; j--) {
            left = max(left, v[j]);
        }
        for (int j = i + 1; j < W; j++) {
            right = max(right, v[j]);
        }

        if (v[i] < min(left, right)) {
            ans += min(left, right) - v[i];
        }
    }
    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed;
    cout.precision(3);

    solved();
    return 0;
}
