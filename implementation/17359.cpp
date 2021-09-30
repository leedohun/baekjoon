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
    vector <string> v(N);
    
    ll ans = 0;
    rep(i, N) {
        cin >> v[i];

        for (int j = 0; j < v[i].size() - 1; j++) {
            if (v[i][j] != v[i][j + 1]) ans++;
        }
    }
    vector<int> idx(N);
    for (int i = 0; i < N; i++) {
        idx[i] = i;
    }
    ll ret = _INF;
    do {
        ll cnt = 0;
        for (int i = 0; i < N - 1; i++) {
            if (v[idx[i]][v[idx[i]].size() - 1] != v[idx[i + 1]][0]) cnt++;
        }

        ret = min(cnt, ret);

    } while (next_permutation(idx.begin(), idx.end()));

    cout << ret + ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
