#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int N, Q;

ll arr[100005] = { 0, };
ll tree[100005] = { 0, }; //BIT tree

void update(int i, ll num) { //BIT Tree 업데이트
	while (i <= N) {
		tree[i] += num;
		i += (i & -i);
	}
}

ll sum(int i) { // BIT Tree 생성
	ll ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];

		update(i, arr[i]);
	}

	for (int i = 0; i < Q; i++) {
		ll x, y, a, b; cin >> x >> y >> a >> b;

		if (y < x) {
			swap(x, y);
		}

		cout << sum(y) - sum(x - 1) << "\n";
		update(a, b - arr[a]);
		arr[a] = b;
	}
}
