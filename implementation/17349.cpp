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
    vector <P> v(9);
    rep(i, 9) cin >> v[i].x >> v[i].y;

    vector <int> ans;
    for (int i = 1; i <= 9; i++) {
        int cnt = 0;
        for (int j = 0; j < 9; j++) {
            if (v[j].y == i && v[j].x == 0) {
                cnt++;
            }
            else if (v[j].y != i && v[j].x == 1) {
                cnt++;
            }
        }
        if (cnt == 1) {
            ans.push_back(i);
        }
    }
    if (ans.size() == 1) cout << ans[0];
    else cout << -1;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
