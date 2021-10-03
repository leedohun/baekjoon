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
    float A, B, C; cin >> A >> B >> C;
    float x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;

    if (A == 0) {
        if (y1 < -C / B && -C / B < y2) cout << "Poor";
        else cout << "Lucky";

        return;
    }
    else if (B == 0) {
        if (x1 < -C / A && -C / A < x2) cout << "Poor";
        else cout << "Lucky";

        return;
    }

    if (A * B < 0) {
        if ((A * x1 + B * y2 + C) * (A * x2 + B * y1 + C) < 0) {
            cout << "Poor";
        }
        else
            cout << "Lucky";
    }
    else {
        if ((A * x2 + B * y2 + C) * (A * x1 + B * y1 + C) < 0) {
            cout << "Poor";
        }
        else
            cout << "Lucky";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
