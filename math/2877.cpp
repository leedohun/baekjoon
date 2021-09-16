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

int ans = 0;

void solved() {
    int K; cin >> K;
    K += 1;

    vector <int> v;
    while (K != 0) {
        v.push_back(K % 2);
        K /= 2;
    }

    reverse(v.begin(), v.end());
    v.erase(v.begin());

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1) cout << 7;
        else cout << 4;
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
