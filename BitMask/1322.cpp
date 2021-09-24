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

void solved() {
    ll N, K; cin >> N >> K;
    ll ans = 0;

    vector <int> v;
    ll cnt = 0;
    for (; N > 0; ) {
        int binary = N % 2;

        if (binary == 0) {
            v.push_back(1); cnt++;
        }
        else
            v.push_back(0);

        N /= 2;
    }
    while (cnt < 33) {
        v.push_back(1);
        cnt++;
    } cnt--;

    for (int i = v.size() - 1; 0 <= i; i--) {
        if (v[i] == 0) continue;
        else {
            if ((ll)pow(2, cnt) <= K) {
                K -= (ll)pow(2, cnt);
                ans += (ll)pow(2, i);
            }
            cnt--;
        }
    }
    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
