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
    int x; int y;
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
    int N; cin >> N;
    vector <P> v(N);
    rep(i, N) cin >> v[i].x >> v[i].y;

    sort(v.begin(), v.end(), cmp);

    int L, P; cin >> L >> P;

    priority_queue <int> pq;

    int ans = 0, j = 0;
    for (int i = 0; i < L; i++) {
        while (j < v.size() && v[j].x <= i) {
            pq.push(v[j++].y);
        }

        if (P - i == 0) {
            if (!pq.empty()) {
                P += pq.top(); pq.pop();
                ans++;
            }
            else {
                cout << -1;
                return;
            }
        }
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
