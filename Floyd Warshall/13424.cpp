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
    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        int Class[105][105] = { 0, };
        rep(i, N + 1) rep(j, N + 1)
            if (i != j)Class[i][j] = INF;

        rep(i, M) {
            int a, b, c; cin >> a >> b >> c;
            Class[a][b] = c;
            Class[b][a] = c;
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (i != j && Class[i][k] + Class[k][j] < Class[i][j])
                        Class[i][j] = Class[i][k] + Class[k][j];
                }
            }
        }

        int K; cin >> K;
        vector <int> stu(K);
        rep(i, K) cin >> stu[i];

        int ans = INF, ret = 0;
        for (int i = 1; i <= N; i++) {
            int cnt = 0;
            for (int j = 0; j < K; j++) {
                cnt += Class[stu[j]][i];
            }
            if (cnt < ans) {
                ret = i, ans = cnt;
            }
        }

        cout << ret << "\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
