#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

int num[1001] = { 0, };
int dp[1005][1005] = { 0, };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	dp[0][0] = 1;
	for (int i = 1; i < N; i++) {
		int ans = 1;
		for (int j = i - 1; 0 <= j; j--) {
			if (num[j] < num[i])
				ans = max(ans, dp[0][j] + 1);
		}
		dp[0][i] = ans;
	}

	for (int i = 0; i < N; i++) {
		int ans = 1;
		dp[i + 1][i] = dp[0][i];
		for (int j = i + 1; j < N; j++) {
			int ans = 1;
			for (int k = j - 1; i <= k; k--) {
				if (num[j] < num[k])
					ans = max(ans, dp[i + 1][k] + 1);
			}
			dp[i + 1][j] = ans;
		}
	}
	int M = 0;
	for (int i = 0; i < 1004; i++) {
		for (int j = 0; j < 1004; j++)
			M = max(dp[i][j], M);
	}
	cout << M;
}
