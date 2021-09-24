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
    int K, N; cin >> K >> N;
    vector <ll> v(K);
    
    set <ll> s;
    priority_queue <ll, vector<ll>, greater<ll>> pq;
    
    rep(i, K) {
        cin >> v[i];
    }

    ll M = 0;
    pq.push(1);

    for (int i = 0; i < N; i++) {
        ll tmp = pq.top(); pq.pop();

        for (int j = 0; j < K; j++) {
            ll next = tmp * v[j];

            if (s.find(next) != s.end()) continue;
            if (pq.size() > N && M < next) continue;

            pq.push(next);
            M = max(M, next);
            s.insert(next);
        }
    }
    cout << pq.top();
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
