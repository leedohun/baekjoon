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
    vector <int> A(N), B(N);

    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    priority_queue <int> pq;
    for (int i = 0; i < N; i++) {
        pq.push(B[i]);
    }

    sort(A.begin(), A.end());

    int idx = 0;
    int answer = 0;
    while (!pq.empty()) {
        answer += pq.top() * A[idx];
        idx++;
        pq.pop();
    }

    cout << answer;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
