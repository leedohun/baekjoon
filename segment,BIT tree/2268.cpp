#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll N, M;
ll tree[4000005] = { 0, };

ll update(int node, int start, int end, int Idx, ll num) { //segment tree update
	if (Idx < start || end < Idx)
		return tree[node];
	if (start == end)
		return tree[node] = num;

	return tree[node] = update(node * 2, start, (start + end) / 2, Idx, num) + update(node * 2 + 1, (start + end) / 2 + 1, end, Idx, num);
}

ll ans(int node, int start, int end, int left, int right) { //결과 값
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	return ans(node * 2, start, (start + end) / 2, left, right) + ans(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y, z; cin >> x >> y >> z;

		if (x == 1) {
			update(1, 1, N, y, z);
		}
		else {
			if (z < y) //y ~ z 일 수도 있고 z ~ y 범위 일 수 있어서 작은 것 부터 시작해서 큰 것 까지 범위를 넣어야 된다.
				swap(y, z);
			cout << ans(1, 1, N, y, z) << "\n";
		}
	}
}
