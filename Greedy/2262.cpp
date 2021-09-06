#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    int N; cin >> N;
    vector <int> v(N);
    rep(i, N) cin >> v[i];

    int ans = 0;

    while (v.size() != 1) {
        int tmp = 0;

        for (int i = 0; i < v.size(); i++) {
            if (tmp < v[i]) {
                tmp = v[i];
            }
        }

        for (int i = 0; i < v.size(); i++) {
            if (tmp == v[i]) {
                if (i == 0) {
                    ans += v[i] - v[i + 1];
                }
                else if (i == v.size() - 1) {
                    ans += v[i] - v[i - 1];
                }
                else {
                    if (v[i - 1] < v[i + 1]) {
                        ans += v[i] - v[i + 1];
                    }
                    else {
                        ans += v[i] - v[i - 1];
                    }
                }
                v.erase(v.begin() + i);
                break;
            }
        }
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
