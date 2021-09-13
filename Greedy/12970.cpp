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
    int N, K; cin >> N >> K;
    vector <char> v(N);

    if (K > (N / 2) * (N - (N / 2))) {
        cout << -1;
        return;
    }

    rep(i, N) v[i] = 'B';

    int j = 0;
    int cnt = N - 1;

    int flag = 0;

    if (K == 0)
        v[N - 1] = 'A';

    while (K != 0) {
        if ((cnt - flag) <= K) {
            v[j++] = 'A';
            K -= (cnt - flag);
            cnt--;

            flag += 1;
        }
        else {
            K += flag;
            while (cnt != K) {
                j++; cnt--;
            }
            v[j] = 'A';
            K = 0;
        }
    }

    rep(i, N) cout << v[i];
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
