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
        int N, M, K; cin >> N >> M >> K;
        vector <int> v(N);
        rep(i, N) cin >> v[i];

        int ret = 0;

        int left = 0, right = M;
        int ans = 0;
        for (int i = left; i < right; i++) {
            ans += v[i];
        }

        if (N == M) {
            if (ans < K) cout << 1 << "\n";
            else cout << 0 << "\n";
            continue;
        }

        do {
            if (ans < K) ret++;

            ans -= v[left];
            ans += v[right];
            left++;
            right++;

            if (left == N) left = 0;
            if (right == N) right = 0;
        } while (right != M);
        cout << ret << "\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
