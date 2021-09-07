#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector <int> v(N);
        rep(i, N) cin >> v[i];

        sort(v.begin(), v.end());

        vector <int> tmp;
        for (int i = 0; i < N; i += 2) {
            tmp.push_back(v[i]);
        }
        if (N % 2 == 0) {
            for (int i = N - 1; 0 <= i; i -= 2) {
                tmp.push_back(v[i]);
            }
        }
        else {
            for (int i = N - 2; 0 <= i; i -= 2) {
                tmp.push_back(v[i]);
            }
        }

        int ans = abs(tmp[N - 1] - tmp[0]);
        rep(i, N - 1) {
            ans = max(ans, abs(tmp[i] - tmp[i + 1]));
        }

        cout << ans << "\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
