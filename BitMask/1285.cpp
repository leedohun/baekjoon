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
    int N; cin >> N;
    int num[21][21];
    rep(i, N) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == 'H') num[i][j] = 1;
            else num[i][j] = 0;
        }
    }

    int ans = INF;
    for (int i = 0; i < pow(2, N); i++) {
        int tmp[21][21];
        rep(i, N) rep(j, N) tmp[i][j] = num[i][j];

        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                for (int k = 0; k < N; k++) {
                    if (tmp[k][j] == 0) tmp[k][j] = 1;
                    else tmp[k][j] = 0;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            int H = 0, T = 0;
            for (int j = 0; j < N; j++) {
                if (tmp[i][j] == 1) H++;
                else if (tmp[i][j] == 0)T++;
            }
            cnt += min(H, T);
        }
        ans = min(ans, cnt);
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
