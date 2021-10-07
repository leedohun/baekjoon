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

int N, K;
int v[10][10] = { 0, };

int ans = INF;

void dfs(bool check[], int cnt, int total, int local) {
    if (cnt == N) {
        ans = min(ans, total);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!check[i] && total < ans) {
            check[i] = true;
            dfs(check, cnt + 1, total + v[local][i], i);
            check[i] = false;
        }
    }
}

void solved() {
    cin >> N >> K;
    rep(i, N) rep(j, N) cin >> v[i][j];

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (v[i][k] + v[k][j] < v[i][j]) {
                    v[i][j] = v[i][k] + v[k][j];
                }
            }
        }
    }
    bool check[10] = { false, };
    check[K] = true;
    dfs(check, 1, 0, K);
    
    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
