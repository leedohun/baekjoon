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

struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y < b.y;
    }
};
priority_queue <P, vector<P>, compare> pq;

bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}

void solved() {
    int N; cin >> N;
    vector <int> v(N + 1);

    for (int i = 1; i <= N; i++) {
        v[i] = i;
    }

    int cnt = 2;
    for (int i = 2; i <= N; i++) {
        if (v[i] != i) continue;

        v[i] = cnt;
        for (int j = 2 * i; j <= N; j += i) {
            v[j] = cnt;
        }
        cnt += 1;
    }

    cout << cnt - 1 << "\n";
    for (int i = 1; i <= N; i++) {
        cout << v[i] << " ";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
