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
int dp[1001] = { 0, };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	dp[0] = num[0];
	
	for (int i = 1; i < N; i++) {
		int ans = 0;
		for (int j = i - 1; 0 <= j; j--) {
			if (num[j] < num[i]) {
				dp[i] = max(dp[i], dp[j] + num[i]);
			}
			else
				dp[i] = max(dp[i], num[i]);
		}
	}

	int M = 0;
	for (int i = 0; i < N; i++)
		M = max(M, dp[i]);
	cout << M;
}
