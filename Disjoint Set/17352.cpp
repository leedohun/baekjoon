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

int parent[300005] = { 0, };

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unionParent(int x, int y) {
    x = find(x);
    y = find(y);

    if (x < y) {
        parent[y] = x;
    }
    else {
        parent[x] = y;
    }
}

void solved() {
    int N; cin >> N;
    rep(i, N + 1) parent[i] = i;

    rep(i, N - 2) {
        int a, b; cin >> a >> b;
        unionParent(a, b);
    }

    for (int i = 1; i <= N; i++) {
        if (parent[i] != parent[i + 1]) {
            int x = find(i);
            int y = find(i + 1);

            if (x != y) {
                cout << i << " " << i + 1;
                return;
            }
        }
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
