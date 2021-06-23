#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
//#include <map>

typedef long long ll;
using namespace std;

int map[3] = { 0, };
int max_dp[2][3] = { 0, };
int min_dp[2][3] = { 0, };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
    
	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[j];
		}

		max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + map[0];
		max_dp[1][1] = max(max_dp[0][0], max(max_dp[0][1], max_dp[0][2])) + map[1];
		max_dp[1][2] = max(max_dp[0][1], max_dp[0][2]) + map[2];

		min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + map[0];
		min_dp[1][1] = min(min_dp[0][0], min(min_dp[0][1], min_dp[0][2])) + map[1];
		min_dp[1][2] = min(min_dp[0][1], min_dp[0][2]) + map[2];

		max_dp[0][0] = max_dp[1][0]; max_dp[0][1] = max_dp[1][1]; max_dp[0][2] = max_dp[1][2];
		min_dp[0][0] = min_dp[1][0]; min_dp[0][1] = min_dp[1][1]; min_dp[0][2] = min_dp[1][2];
	}

	cout << max(max_dp[0][0], max(max_dp[0][1], max_dp[0][2])) << " " << min(min_dp[0][0], min(min_dp[0][1], min_dp[0][2]));
}

/*
DP 문제로 자기 자신의 자리는 바로 위에 위치한 값들 중 가장 큰 값과 가장 작은 값을 골라주면 됩니다.

점화식
   dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + map[i][0];
   dp[i][1] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2])) + map[i][1];
   dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + map[i][2];
*/
