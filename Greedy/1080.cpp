#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;

const ll _INF = 1e18;
const ll INF = 1e9;

void solved() {
    int N, M; cin >> N >> M;
    string A[50], B[50];
    
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    int ans = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (A[i][j] != B[i][j]) {
                ans++;
                for (int q = i; q < i + 3; q++) {
                    for (int p = j; p < j + 3; p++) {
                        if (A[q][p] == '0') {
                            A[q][p] = '1';
                        }
                        else
                            A[q][p] = '0';
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != B[i][j]) {
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << ans << "\n";
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
