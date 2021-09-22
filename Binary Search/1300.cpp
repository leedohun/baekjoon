#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*#include <iostream>
#include <string>
#include <queue>
#include <set>*/

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y; int cnt;
};

/*struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y < b.y;
    }
};
priority_queue <P, vector<P>, compare> pq;*/

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

void solved() {
    ll N, K; cin >> N >> K;

    ll left = 1, right = K;

    ll result = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;

        ll cnt = 0;
        for (int i = 1; i <= N; i++) {
            cnt += min(N, mid / i);
        }

        if (cnt < K) left = mid + 1;
        else {
            result = mid;
            right = mid - 1;
        }
    }
    cout << result;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
