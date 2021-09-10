#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

struct P {
    int x; int y;
};

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

    int ans = 0;
    int idx = N - 1;
    priority_queue <int> pq;
    
    for (int i = N; 0 < i; i--) {
        for (; idx >= 0 && v[idx].x == i;) {
            pq.push(v[idx].y);
            idx--;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
