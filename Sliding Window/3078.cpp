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
    int N, K; cin >> N >> K;
    vector <int> v(N);
    rep(i, N) {
        string tmp; cin >> tmp;
        v[i] = tmp.size();
    }

    map <int, int> m;
    for (int i = 0; i <= K; i++) {
        if (m.find(v[i]) != m.end()) m[v[i]]++;
        else m[v[i]] = 1;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += m[v[i]] - 1;

        m[v[i]]--;
        if (i + K + 1 < N) {
            if (m.find(v[i + K + 1]) != m.end()) m[v[i + K + 1]]++;
            else m[v[i + K + 1]] = 1;
        }
    }
    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
