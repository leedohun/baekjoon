#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>

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
    int N, M, L; cin >> N >> M >> L;
    vector <int> v(M + 2);
    v[0] = 0; v[M + 1] = L;
    rep(i, M) cin >> v[i + 1];

    while (N--) {
        int Q; cin >> Q;

        int fir = 0, sec = L, tmp = 0;
        while (fir <= sec) {
            int mid = (fir + sec) / 2;

            int cnt = Q + 1, loc = 0;
            for (int i = 1; i <= M + 1; i++) {
                if (v[i] - loc >= mid) {
                    cnt--;
                    loc = v[i];
                }
            }

            if (cnt <= 0) {
                fir = mid + 1;
            }
            else {
                sec = mid - 1;
            }
        }
        cout << sec << "\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
