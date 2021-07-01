#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int num[10] = { 0, 0, 1, 7, 4, 2, 0, 8, 10, 0 };
ll dp[105] = { 0, 0, 1, 7, 4, 2, 6, 8, 10, };

void max_solve(int n) { //가장 큰 수는 홀수면 맨앞에 7 다음에 1을 계속, 짝수면 1만 계속
    if (n % 2 == 1) {
        cout << 7; n -= 3;
        while (n) {
            cout << 1;
            n -= 2;
        }
    }
    else {
        while (n) {
            cout << 1;
            n -= 2;
        }
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;

    for (int i = 9; i < 101; i++) {
        dp[i] = LONG_MAX;
        for (int j = 2; j <= 7; j++) { //n이 2 ~ 8까지의 값을 구한 뒤 dp를 이용
            dp[i] = min(dp[i - j] * 10 + num[j], dp[i]);
        }
    }

    while (t--) {
        int n; cin >> n;

        cout << dp[n] << " ";
        max_solve(n);
        cout << "\n";
    }
}
