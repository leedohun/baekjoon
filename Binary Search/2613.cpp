#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    int N, M; cin >> N >> M;
    vector <int> v(N);
    
    int L = 0;
    int R = 100 * N;
    rep(i, N) {
        cin >> v[i];
        L = max(L, v[i]);
    }

    while (L <= R) {
        int mid = (L + R) / 2;

        int cnt = 1, tmp = 0;
        for (int i = 0; i < N; i++) {
            tmp += v[i];
            if (tmp > mid) {
                tmp = v[i];
                cnt++;
            }
        }
        if (cnt <= M) {
            R = mid - 1;
        }
        else {
            L = mid + 1;
        }
    }
    cout << L << "\n";

    int num = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i];
        if (sum > L) {
            sum = v[i];
            M--;
            cout << num << " ";
            num = 0;
        }
        num++;

        if (N - i == M) break;
    }

    while (M--) {
        cout << num << " ";
        num = 1;
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
