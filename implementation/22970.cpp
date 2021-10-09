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

void solved() {
    int N; cin >> N;
    vector <int> v(N);
    rep(i, N) cin >> v[i];
    
    vector <int> M(N), m(M);
    M[0] = 1;
    for (int i = 1; i < N; i++) {
        if (v[i - 1] < v[i]) M[i] = M[i - 1] + 1;
        else M[i] = 1;
    }
    m[N - 1] = 1;
    for (int i = N - 2; 0 <= i; i--) {
        if (v[i + 1] < v[i]) m[i] =m[i + 1] + 1;
        else m[i] = 1;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (ans < m[i] + M[i]) {
            ans = m[i] + M[i];
        }
    }
    cout << ans - 1;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
