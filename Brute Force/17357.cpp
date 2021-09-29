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
    vector <int> v(N);
    rep(i, N) cin >> v[i];

    for (int k = 1; k <= N; k++) {
        double ans = 0; int lo = 0;
        for (int i = 0; i + k <= N; i++) {
            ll total = 0;
            for (int j = i; j < i + k; j++) {
                total += v[j];
            }

            double m = (double)total / k;
            double V = 0;
            for (int j = i; j < i + k; j++) {
                V += pow(((double)v[j] - m), 2);
            }
            V /= k;
            
            if (ans < sqrt(V)) {
                ans = sqrt(V);
                lo = i;
            }
        }
        cout << lo + 1 << "\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
