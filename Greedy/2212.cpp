#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    int N, K; cin >> N >> K;
    set <int> s;
    rep(i, N) {
        int tmp; cin >> tmp;
        s.insert(tmp);
    }

    priority_queue <int> pq;
    vector <int> v;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        v.push_back(*iter);
    }

    for (int i = 0; i < v.size() - 1; i++) {
        pq.push(v[i + 1] - v[i]);
    }

    for (int i = 0; i < K - 1; i++) {
        if (!pq.empty()) pq.pop();
    }

    int ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}

/*
각 센서의 양 옆 수신 거리의 차이를 pq에 넣어서 K-1개 만 제거한 뒤 모두 더한 것이 답이다.
*/
