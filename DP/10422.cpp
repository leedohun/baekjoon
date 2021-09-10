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
    int t; cin >> t;
    
    vector <ll> v(5005);
    v[0] = 1; v[1] = 0; v[2] = 1;
    for (int i = 3; i < 5005; i++) {
        for (int j = 2; j <= i; j++) {
            v[i] += (v[j - 2] * v[i - j]) % 1000000007;
        }
        v[i] %= 1000000007;
    }

    while (t--) {
        int n; cin >> n;
        cout << v[n] << "\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
