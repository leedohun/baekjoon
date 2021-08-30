#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    int N, K; cin >> N >> K;

    if (N == K) {
        cout << 0;
        return;
    }

    vector <int> v(N);
    rep(i, N)
        cin >> v[i];

    sort(v.begin(), v.end());

    if (K == 1) {
        cout << v[N - 1] - v[0];
        return;
    }

    priority_queue <pair<int, int>> pq;
    for (int i = 1; i < N; i++) {
        pq.push({ v[i] - v[i - 1], i - 1 });
    }

    vector <int> local;
    for (int i = 0; i < K - 1; i++) {
        local.push_back(pq.top().second);
        pq.pop();
    }

    sort(local.begin(), local.end());

    ll ans = 0;
    ans += v[local[0]] - v[0];
    for (int i = 1; i < local.size(); i++) {
        ans += v[local[i]] - v[local[i - 1] + 1];
    }
    ans += v[v.size() - 1] - v[local[K - 2] + 1];

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
