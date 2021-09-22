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
    int N; cin >> N;
    vector<int> v(N), tmp(N);
    rep(i, N) {
        cin >> v[i];
        tmp[i] = v[i];
    }

    sort(tmp.begin(), tmp.end());
    
    map <int, int> m;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (m.find(tmp[i]) == m.end()) {
            m[tmp[i]] = cnt++;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << m[v[i]] << " ";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
