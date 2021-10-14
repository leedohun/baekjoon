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
        int n; cin >> n;
        set <int> s;
        vector <int> v(n);
        rep(i, n) {
            cin >> v[i];
            s.insert(v[i]);
        }

        int ans = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((v[j] + v[i]) % 2 == 1 || (v[j] + v[i]) % 2 == -1) continue;
                if (s.find((v[j] + v[i]) / 2) != s.end()) ans++;
            }
        }
        cout << ans << "\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
