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
    vector <ll> v(50);
    v[1] = 1; v[2] = 1;
    for (int i = 3; i < 50; i++) {
        v[i] = v[i - 1] + v[i - 2];
    }

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;

        vector <ll> ans;
        for (int i = 49; 0 <= i; i--) {
            if (v[i] <= N) {
                ans.push_back(v[i]);
                N -= v[i];
            }

            if (N == 0) break;
        }
        sort(ans.begin(), ans.end());

        rep(i, ans.size()) cout << ans[i] << " ";
        cout << "\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
