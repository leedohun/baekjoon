#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll N, M, K;

ll tree[4000005] = { 0, };

//update 과정에서 곱하기 이기 때문에 0이 들어오게 된다면 탑 다운 방식으로는 문제가 생길 수 있다. 따라서 바텀 업으로 update를 해야된다.
ll update(int node, int start, int end, int Idx, ll num) { //segment update
	if (Idx < start || end < Idx)
		return tree[node];
	if (start == end)
		return tree[node] = num;

	return tree[node] = (update(node * 2, start, (start + end) / 2, Idx, num) * update(node * 2 + 1, (start + end) / 2 + 1, end, Idx, num)) % 1000000007;
}

ll ans(int node, int start, int end, int left, int right) { //segment result
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[node];

	return (ans(node * 2, start, (start + end) / 2, left, right) * ans(node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % 1000000007;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		int temp;  cin >> temp;

		update(1, 1, N, i, temp); //segment update
	}

	for (int i = 0; i < M + K; i++) {
		int x, y, z; cin >> x >> y >> z;

		if (x == 1) {
			update(1, 1, N, y, z);
		}
		else {
			cout << ans(1, 1, N, y, z) << "\n";
		}
	}
}
