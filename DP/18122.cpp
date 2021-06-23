#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

vector <int> dp;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
    
	int N; cin >> N;

	dp.push_back(3);

	for (int i = 1; i < N; i++) {
		dp.push_back(((v[i - 1] * 2) % 1000000007 + 5) % 1000000007);
	}
	cout << dp[N - 1];
}

/*
N : 1  --> result : 3
N : 2  --> result : 11
N : 3  --> result : 27
N : 4  --> result : 59
N : 5  --> result : 123
N : 6  --> result : 251
N : 7  --> result : 507
N : 8  --> result : 1019
N : 9  --> result : 2043
N : 10 --> result : 4091
. . .

점화식을 세워보면 dp[i] = dp[i-1] * 2 + 5 가 나옵니다.
*/
