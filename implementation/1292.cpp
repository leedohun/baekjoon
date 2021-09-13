#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    vector <int> v;

    for (int i = 1; i <= 50; i++) {
        for (int j = 0; j < i; j++) {
            v.push_back(i);
        }
    }

    int ans = 0;
    int A, B; cin >> A >> B;

    for (int i = A - 1; i < B; i++) {
        ans += v[i];
    }

    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
