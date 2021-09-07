#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    int N, L; cin >> N >> L;
    vector <int> v(N);
    rep(i, N) cin >> v[i];

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        int m = v[i];
        ans++;
        
        while (i + 1 < N && m + L < v[i + 1])
            i++;
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
