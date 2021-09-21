#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001] = { 0, };
int dp[1001] = { 0, };
int N;

int main() {
	int max = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	dp[1] = 1;
	for (int i = 1; i <= N; i++) {
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				if (min < dp[j]) min = dp[j];
			}
		}
		dp[i] = min + 1;
		if (max < dp[i]) max = dp[i];
	}
	printf("%d", max);
}
