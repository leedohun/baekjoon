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

int N;
int v[105] = { 0, };
bool check[105] = { false, };
vector <int> ans;

void dfs(int x, int y) {
    if (check[x]) {
        if (x == y)
            ans.push_back(y);
    }
    else {
        check[x] = true;
        dfs(v[x], y);
    }
}

void solved() {
    cin >> N;
    rep(i, N) cin >> v[i + 1];

    for (int i = 1; i <= N; i++) {
        memset(check, 0, 105);
        dfs(i, i);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
